


/*--------------------------------------------------------------------*/

#ifndef _TREERB_H_
#define _TREERB_H_

#include <stdbool.h>

typedef int Element;
typedef enum colour{RED, BLACK} Couleur;

typedef struct noeud{
    Element value; /** Contenu du noeud*/
    bool couleur; /** ARB équilibre: bal*/
    struct noeud* childLeft; /** Sousracine à gauche*/
    struct noeud* childRight; /** Sousracine à droite*/
    struct noeud* parent;
} Noeud;

typedef Noeud* pt_Arbre;
typedef pt_Arbre ARB;


/*--------------------------------------------------------------------*/
ARB create(Element x);
int Noeuds(ARB racine);
ARB parent(ARB node);
ARB grandparent(ARB node);
ARB sibling(ARB node);
ARB oncle(ARB node);

void RotD(ARB racine, ARB node);
void RotG(ARB racine, ARB node);
void Descendre(ARB node, ARB pnode);
bool isLeftChild(ARB node);
bool hasRedChild(ARB node);

ARB Ajouter (ARB racine, Element value);
void Reparer(ARB racine, ARB node);
bool Supprimer(ARB racine, Element val);
void Liberer(ARB racine);
ARB Rechercher(ARB racine, Element v);
ARB Remplacer(ARB node);
ARB Successeur(ARB node);
ARB Remplacer(ARB node);

void afficherARBPreOrder(ARB racine);
void afficherARBInOrder(ARB racine);
void afficherARBPostOrder(ARB racine);
void afficherARBTopo(ARB racine, int space);


#endif



