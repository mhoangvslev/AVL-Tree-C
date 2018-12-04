#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "TreeAVL.h"

#include <stdbool.h>

AVL create (Element x)
{
    AVL res = (AVL) malloc(sizeof(Element) + sizeof(int) + 2*sizeof(AVL));
    if(res)
    {
        res->value = x;
        res->bal = 0;
        res->childLeft= NULL;
        res->childRight = NULL;
        return res;
    }

    return NULL;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int hauteur (AVL arbre)
{
    if(arbre)
        return 1 + max(hauteur(arbre->childLeft), hauteur(arbre->childRight));
    return 0;
}

int Noeuds(AVL arbre)
{
    if(arbre)
        return 1 + Noeuds(arbre->childLeft) + Noeuds(arbre->childRight);
    return 0;
}

AVL RotD(AVL arbre)
{
    AVL left = arbre->childLeft;
    AVL leftright = left->childRight;

    // Rotation
    left->childRight = arbre;
    arbre->childLeft = leftright;

    return left;
}

AVL RotG(AVL arbre)
{
    AVL right = arbre->childRight;
    AVL rightleft = right->childLeft;

    // Rotation
    right->childLeft = arbre;
    arbre->childRight = rightleft;

    return right;
}

int getBalance(AVL arbre)
{
    if(arbre)
        return hauteur(arbre->childLeft) - hauteur(arbre->childRight);
    return 0;
}

AVL UpdateAjouter(Element v, AVL arbre)
{
    int balance = getBalance(arbre);
    //printf("Balance: %d\n", balance);

    // LL
    if(balance > 1 && v < arbre->childLeft->value){
        //printf("Arbre deséquilibré au noeud %d\n--> Double rotation Gauche\n", arbre->childLeft->value);
        return RotD(arbre);
    }

    // RR
    if(balance < -1 && v > arbre->childRight->value){
        //printf("Arbre deséquilibré au noeud %d\n--> \n Double rotation droite\n", arbre->childRight->value);
        return RotG(arbre);
    }

    // LR
    if (balance > 1 && v > arbre->childLeft->value){
        //printf("Arbre deséquilibré au noeud %d\n--> Rotation gauche puis droite\n", arbre->childLeft->value);
        arbre->childLeft =  RotG(arbre->childLeft);
        return RotD(arbre);
    }

    // RL
    if (balance < -1 && v < arbre->childRight->value){
        //printf("Arbre deséquilibré au noeud %d\n--> Rotation droite puis gauche\n", arbre->childRight->value);
        arbre->childRight = RotD(arbre->childRight);
        return RotG(arbre);
    }

    //printf("Arbre équilibré.\n");
    return arbre;
}


AVL Ajouter (Element v, AVL arbre)
{
    if(arbre == NULL)
    {
        //printf("Arbre vide, créer un arbre avec la valeur %d\n", v);
        return create(v);
    }

    if(v < arbre->value)
    {
        //printf("Insertion à gauche la valeur %d\n", v);
        arbre->childLeft = Ajouter(v, arbre->childLeft);
    }
    else if(v > arbre->value)
    {
        //printf("Insertion à droite la valeur %d\n", v);
        arbre->childRight = Ajouter(v, arbre->childRight);
    }
    else
    {
        //printf("Valeur %d déjà existant, pass!", v);
        return arbre;
    }

    return UpdateAjouter(v, arbre);
}

AVL minValueNode(AVL arbre)
{
    AVL current = arbre;

    /* Chercher la feuille la plus gauche */
    while (current->childLeft != NULL)
        current = current->childLeft;

    return current;
}

AVL UpdateSupprimer(AVL arbre){
    int balance = getBalance(arbre);
    //printf("Balance: %d\n", balance);

    // LL
    if(balance > 1 && getBalance(arbre->childLeft) >= 0){
        //printf("Arbre deséquilibré au noeud %d\n--> Double rotation Gauche\n", arbre->childLeft->value);
        return RotD(arbre);
    }

    // RR
    if(balance < -1 && getBalance(arbre->childRight) <= 0){
        //printf("Arbre deséquilibré au noeud %d\n--> \n Double rotation droite\n", arbre->childRight->value);
        return RotG(arbre);
    }

    // LR
    if (balance > 1 && getBalance(arbre->childLeft) < 0){
        //printf("Arbre deséquilibré au noeud %d\n--> Rotation gauche puis droite\n", arbre->childLeft->value);
        arbre->childLeft =  RotG(arbre->childLeft);
        return RotD(arbre);
    }

    // RL
    if (balance < -1 && getBalance(arbre->childRight) > 0){
        //printf("Arbre deséquilibré au noeud %d\n--> Rotation droite puis gauche\n", arbre->childRight->value);
        arbre->childRight = RotD(arbre->childRight);
        return RotG(arbre);
    }

    //printf("Arbre équilibré.\n");
    return arbre;
}

AVL Supprimer(Element v, AVL arbre)
{
    if(arbre == NULL)
    {
        return arbre;
    }
    else if (v < arbre->value)
    {
        arbre->childLeft = Supprimer(v, arbre->childLeft);
    }
    else if (v > arbre->value)
    {
        arbre->childRight = Supprimer(v, arbre->childRight);
    }
    else
    {
        if(arbre->childLeft == NULL || arbre->childRight == NULL)
        {
            AVL temp = arbre->childLeft ? arbre->childLeft : arbre->childRight;
            if(temp == NULL)
            {
                temp = arbre;
                arbre = NULL;
            }
            else
                *arbre = *temp;
            free(temp);
        }
        else
        {
            AVL temp = minValueNode(arbre->childRight);
            arbre->value = temp->value;
            arbre->childRight = Supprimer(temp->value, arbre->childRight);
        }

    }

    if(arbre == NULL) return arbre;

    // Mettre à jour
    return UpdateSupprimer(arbre);
}

void Liberer(AVL arbre)
{
    if(arbre)
    {
        Liberer(arbre->childLeft);
        Liberer(arbre->childRight);
    }

    free(arbre);
}

bool Rechercher(Element v, AVL arbre)
{
    if(arbre)
    {
        if(arbre->value == v)
            return true;
        else
            return Rechercher(v, arbre->childLeft) || Rechercher(v, arbre->childRight);
    }
    return false;
}

void afficherAVLPreOrder(AVL arbre)
{
    if(arbre)
    {
        printf("%d :: ", arbre->value);
        afficherAVLPreOrder(arbre->childLeft);
        afficherAVLPreOrder(arbre->childRight);
    }
}

void afficherAVLInOrder(AVL arbre)
{
    if(arbre)
    {
        afficherAVLInOrder(arbre->childLeft);
        printf("%d :: ", arbre->value);
        afficherAVLInOrder(arbre->childRight);
    }
}

void afficherAVLPostOrder(AVL arbre)
{
    if(arbre)
    {
        afficherAVLPostOrder(arbre->childLeft);
        afficherAVLPostOrder(arbre->childRight);
        printf("%d :: ", arbre->value);
    }
}

void afficherAVLTopo(AVL arbre, int space)
{
    int COUNT = 10;
    // Base case
    if (arbre == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    afficherAVLTopo(arbre->childRight, space);

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", arbre->value);

    // Process left child
    afficherAVLTopo(arbre->childLeft, space);
}
