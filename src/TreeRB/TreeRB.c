#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "TreeRB.h"

#include <stdbool.h>

ARB create(Element x)
{
    ARB res = (ARB) malloc(sizeof(Element) + sizeof(Couleur) + 3*sizeof(ARB));
    if(res)
    {
        res->value = x;
        res->couleur = RED;
        res->childLeft= NULL;
        res->childRight = NULL;
        res->parent = NULL;
        return res;
    }

    return NULL;
}

int Noeuds(ARB racine)
{
    if(racine)
        return 1 + Noeuds(racine->childLeft) + Noeuds(racine->childRight);
    return 0;
}

ARB parent(ARB node)
{
    return node->parent;
}

ARB grandparent(ARB node)
{
    ARB p = parent(node);
    return (p) ? p->parent : NULL;
}

ARB sibling(ARB node)
{
    ARB p = node->parent;
    if(parent)
    {
        return ( node == p->childLeft ) ? p->childRight : p->childLeft;
    }
    return NULL;
}

ARB oncle(ARB node)
{
    ARB p = parent(node);
    ARB gp = grandparent(node);
    return (gp) ? sibling(p) : NULL;
}

void Descendre(ARB node, ARB pnode)
{
    ARB p = node->parent;
    if(p)
    {
        if(isLeftChild(node))
            p->childLeft = pnode;
        else
            p->childRight = pnode;
    }

    pnode->parent = p;
    p = pnode;
}

bool isLeftChild(ARB node)
{
    return node == node->parent->childLeft;
}

bool hasRedChild(ARB node)
{
    return ( (node->childLeft && node->childLeft->couleur == RED) || (node->childRight && node->childRight->couleur == RED));
}

void RotG(ARB racine, ARB node)
{
    ARB newnode = node->childRight;

    if(node == racine)
        racine = newnode;

    Descendre(node, newnode);

    node->childRight = newnode->childLeft;

    if(newnode->childLeft)
        newnode->childLeft->parent = node;

    newnode->childLeft = node;
}

void RotD(ARB racine, ARB node)
{
    ARB newnode = node->childLeft;

    if(node == racine)
        racine = newnode;

    Descendre(node, newnode);

    node->childLeft = newnode->childRight;

    if(newnode->childRight)
        newnode->childRight->parent = node;

    newnode->childRight = node;

}

void EchangerCouleur(ARB a, ARB b)
{
    //printf("Echanger %d(%d) et %d(%d)\n", a->value, a->couleur, b->value, b->couleur);
    Couleur temp = a->couleur;
    a->couleur = b->couleur;
    b->couleur = temp;
    //printf("Résulat %d(%d) et %d(%d)\n", a->value, a->couleur, b->value, b->couleur);
}

void EchangerValeur(ARB a, ARB b){
    Element temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void Reparer(ARB racine, ARB node)
{
    ARB p = NULL;
    ARB gp = NULL;

    while( (node != racine) && (node->couleur != BLACK) && (node->parent->couleur == RED) )
    {
        p = node->parent;
        gp = node->parent->parent;

        // Cas A: Parent de node est l'enfant à gauche de son grand-parent
        if(p == gp->childLeft)
        {
            //ARB o = gp->childRight;
            ARB o = oncle(node);
            if(o && o->couleur == RED)
            {
                // Cas 1: Si l'oncle est aussi RED
                //printf("A1 n[%d(%d)], p[%d(%d)], o[%d(%d)], gp[%d(%d)]\n", node->value, node->couleur, p->value, p->couleur, o->value, o->couleur, gp->value, gp->couleur);
                gp->couleur = RED;
                p->couleur = BLACK;
                o->couleur = BLACK;
                node = gp;
                Reparer(racine, node);
            }
            else
            {
                if(node == p->childRight)
                {
                    //printf("A2 n[%d(%d)], p[%d(%d)], o[%d(%d)], gp[%d(%d)]\n", node->value, node->couleur, p->value, p->couleur, o->value, o->couleur, gp->value, gp->couleur);
                    // Cas 2: si node est l'enfant à droite de son parent
                    RotG(racine, node);
                    node = p;
                    p = node->parent;
                }
                // Cas 3: si node est l'enfant à gauche
                //printf("A3 n[%d(%d)], p[%d(%d)], o[%d(%d)], gp[%d(%d)]\n", node->value, node->couleur, p->value, p->couleur, o->value, o->couleur, gp->value, gp->couleur);
                RotD(racine, gp);
                EchangerCouleur(p, gp);
                node = p;
            }
        }
        // Cas B: Parent de node est l'enfant à droite de son grand-parent
        else
        {
            //ARB o = gp->childRight;
            ARB o = oncle(node);
            if(o && o->couleur == RED)
            {
                // Cas 1: Si l'oncle est aussi RED
                //printf("B1 n[%d(%d)], p[%d(%d)], o[%d(%d)], gp[%d(%d)]\n", node->value, node->couleur, p->value, p->couleur, o->value, o->couleur, gp->value, gp->couleur);
                p->couleur = BLACK;
                o->couleur = BLACK;
                gp->couleur = RED;
                node = gp;
            }
            else
            {
                if(node == p->childLeft)
                {
                    // Cas 2: si node est l'enfant à droite de son parent
                    //printf("B2 n[%d(%d)], p[%d(%d)], o[%d(%d)], gp[%d(%d)]\n", node->value, node->couleur, p->value, p->couleur, o->value, o->couleur, gp->value, gp->couleur);
                    RotD(racine, node);
                    node = p;
                    p = node->parent;
                }
                // Cas 3: si node est l'enfant à gauche
                //printf("B3 n[%d(%d)], p[%d(%d)], o[%d(%d)], gp[%d(%d)]\n", node->value, node->couleur, p->value, p->couleur, o->value, o->couleur, gp->value, gp->couleur);
                RotG(racine, gp);
                EchangerCouleur(p, gp);
                node = p;
            }
        }
    }
    racine->couleur = BLACK;
}

ARB AjouterNoeud (ARB racine, ARB node)
{
    if(racine == NULL)
    {
        //printf("Racine vide, replacée par un nouvel racine de valeur %d\n", node->value);
        return node;
    }

    if(node->value < racine->value)
    {
        //printf("Insertion à gauche la valeur %d\n", node->value);
        racine->childLeft = AjouterNoeud(racine->childLeft, node);
        racine->childLeft->parent = racine;

    }
    else if(node->value > racine->value)
    {
        //printf("Insertion à droite la valeur %d\n", node->value);
        racine->childRight = AjouterNoeud(racine->childRight, node);
        racine->childRight->parent = racine;
    }

    //printf("Valeur %d déjà existant, pass!", v);
    return racine;
}

ARB Ajouter (ARB racine, Element value)
{
    ARB node = create(value);
    racine = AjouterNoeud(racine, node);
    Reparer(racine, node);
    return racine;
}

void Liberer(ARB racine)
{
    if(racine)
    {
        Liberer(racine->childLeft);
        Liberer(racine->childRight);
        //Liberer(racine->parent);
        free(racine);
    }
}

ARB Rechercher(ARB racine, Element v)
{
    if(racine)
    {
        if(racine->value == v) return racine;
        else if (v < racine->value) return Rechercher(racine->childLeft, v);
        else if (v > racine->value) return Rechercher(racine->childRight, v);
        else return NULL;
    }
    return NULL;
}

ARB Successeur(ARB node){
    ARB temp = node;
    while(temp->childLeft){
        temp = temp->childLeft;
    }

    return temp;
}

ARB Remplacer(ARB node){
    if(node->childLeft && node->childRight){
        return Successeur(node->childRight);
    }
    else if(node->childLeft == NULL && node->childRight == NULL){
        return NULL;
    }else if(node->childLeft){
        return node->childLeft;
    }else{
        return node->childRight;
    }
}

void SupprimerNoeud(ARB racine, ARB v)
{
    ARB u = Remplacer(v);
    bool uvBlack = ((u == NULL || u->couleur == BLACK) && (v->couleur == BLACK));
    ARB p = v->parent;

    if (u == NULL)
    {
        if (v == racine)
        {
            racine = NULL;
        }
        else
        {
            if (uvBlack) Reparer(racine, v);
            else
            {
                if (sibling(v) != NULL)
                    sibling(v)->couleur = RED;
            }

            // Supprimmer v
            if (isLeftChild(v)) p->childLeft = NULL;
            else p->childRight = NULL;
        }
        Liberer(v);
        return;
    }

    if (v->childLeft == NULL || v->childRight == NULL)
    {
        if (v == racine)
        {
            v->value = u->value;
            v->childLeft = v->childRight = NULL;
            Liberer(u);
        }
        else
        {
            // Detach v from tree and move u up
            if (isLeftChild(v)) p->childLeft = u;
            else p->childRight = u;

            Liberer(v);
            u->parent = p;

            if (uvBlack) Reparer(racine, u);
            else u->couleur = BLACK;
        }
        return;
    }

    // v has 2 children, swap values with successor and recurse
    EchangerValeur(u, v);
    SupprimerNoeud(racine, u);
}

bool Supprimer(ARB racine, Element val){
    if(racine){
        ARB u = Rechercher(racine, val);
        if(u){
            SupprimerNoeud(racine, u);
            return true;
        }
        else{
            printf("\nLe noeud %d n'est pas présent dans l'arbre.\n", val);
            return false;
        }
    }
}

void afficherARBPreOrder(ARB racine)
{
    if(racine)
    {
        printf("%d :: ", racine->value);
        afficherARBPreOrder(racine->childLeft);
        afficherARBPreOrder(racine->childRight);
    }
}

void afficherARBInOrder(ARB racine)
{
    if(racine)
    {
        afficherARBInOrder(racine->childLeft);
        printf("%d :: ", racine->value);
        afficherARBInOrder(racine->childRight);
    }
}

void afficherARBPostOrder(ARB racine)
{
    if(racine)
    {
        afficherARBPostOrder(racine->childLeft);
        afficherARBPostOrder(racine->childRight);
        printf("%d :: ", racine->value);
    }
}

char* colourToString(Couleur clr)
{
    switch(clr)
    {
    case RED:
        return "R";
    case BLACK:
    default:
        return "B";
    }
}

void afficherARBTopo(ARB racine, int space)
{
    int COUNT = 10;
    // Base case
    if (racine == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    afficherARBTopo(racine->childRight, space);

    // Print current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d(%s)\n", racine->value, colourToString(racine->couleur));

    // Process left child
    afficherARBTopo(racine->childLeft, space);
}



