


/*--------------------------------------------------------------------*/

#ifndef _TREEAVL_H_
#define _TREEAVL_H_

#include <stdbool.h>

typedef int Element;

typedef struct noeud{
    Element value; /** Contenu du noeud*/
    int bal; /** AVL équilibre: bal*/
    struct noeud* childLeft; /** Sousarbre à gauche*/
    struct noeud* childRight; /** Sousarbre à droite*/
} Noeud;

typedef Noeud* pt_Arbre;
typedef pt_Arbre AVL;


/*--------------------------------------------------------------------*/
AVL create (Element x);
int hauteur (AVL arbre);
int Noeuds(AVL arbre);
AVL RotD(AVL arbre);
AVL RotG(AVL arbre);
AVL Ajouter (Element v, AVL arbre);
AVL Supprimer(Element v, AVL arbre);
int getBalance(AVL arbre);
void Liberer(AVL arbre);
bool Rechercher(Element v, AVL arbre);
void afficherAVLPreOrder(AVL arbre);
void afficherAVLInOrder(AVL arbre);
void afficherAVLPostOrder(AVL arbre);
void afficherAVLTopo(AVL arbre, int space);

#endif



