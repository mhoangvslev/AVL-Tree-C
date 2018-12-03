#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "TreeAVL.h"

#include <stdbool.h>

AVL create (Element x)
{
    AVL res = malloc(sizeof(Element) + sizeof(int) + 2*sizeof(AVL));
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

int hauteur (AVL arbre)
{
    if(arbre)
    {
        int h = 1;
        int hl = hauteur(arbre->childLeft);
        int hr = hauteur(arbre->childRight);
        return h + (hl > hr) ? hl : hr;
    }
    return 0;
}

int Noeuds(AVL arbre)
{
    if(arbre)
    {
        return 1 + Noeuds(arbre->childLeft) + Noeuds(arbre->childRight);
    }
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
    right->childRight = arbre;
    arbre->childLeft = rightleft;

    return right;
}

int getBalance(AVL arbre)
{
    if(arbre)
        return hauteur(arbre->childLeft) - hauteur(arbre->childRight);
    return 0;
}

AVL Update(Element v, AVL arbre)
{
    int balance = getBalance(arbre);

    // LL
    if(balance > 1 && v < arbre->childLeft->value)
        return RotD(arbre);

    // RR
    if(balance < -1 && v > arbre->childRight->value)
        return RotG(arbre);

    // LR
    if (balance > 1 && v > arbre->childLeft->value)
    {
        arbre->childLeft =  RotG(arbre->childLeft);
        return RotD(arbre);
    }

    // RL
    if (balance < -1 && v < arbre->childRight->value)
    {
        arbre->childRight = RotD(arbre->childRight);
        return RotG(arbre);
    }
    return arbre;
}


AVL Ajouter (Element v, AVL arbre)
{
    if(arbre == NULL)
    {
        return create(v);
    }

    if(v < arbre->value)
    {
        arbre->childLeft = Ajouter(v, arbre->childLeft);
    }
    else if(v > arbre->value)
    {
        arbre->childRight = Ajouter(v, arbre->childRight);
    }
    else
    {
        return arbre;
    }

    return Update(v, arbre);
}

AVL minValueNode(AVL arbre)
{
    AVL current = arbre;

    /* Chercher la feuille la plus gauche */
    while (current->childLeft != NULL)
        current = current->childLeft;

    return current;
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
    return Update(v, arbre);
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

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", arbre->value);

    // Process left child
    afficherAVLTopo(arbre->childLeft, space);
}
