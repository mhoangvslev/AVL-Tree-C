#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "TreeRB.h"



int main()
{
    ARB root = NULL;

    printf("Test insertion (donc RotD, RotG): \n");

    root = Ajouter(root, 7);
    assert(root->value == 7);

    root = Ajouter(root, 2);
    assert(root->childLeft->value == 2);

    root = Ajouter(root, 11);
    assert(root->childRight->value == 11);

    root = Ajouter(root, 1);
    assert(root->childLeft->childLeft->value == 1);

    root = Ajouter(root, 5);
    assert(root->childLeft->childRight->value == 5);

    root = Ajouter(root, 8);
    assert(root->childRight->childLeft->value == 8);

    root = Ajouter(root, 14);
    assert(root->childRight->childRight->value == 14);

    root = Ajouter(root, 4);
    assert(root->childLeft->childRight->childLeft->value == 4);

    root = Ajouter(root, 15);
    assert(root->childRight->childRight->childRight->value == 15);


    printf("OK!\n");

    printf("Test Noeuds: \n");
    //assert( Noeuds(root) == 9 );
    printf("OK!\n");

    printf("Test PreOrderTraversal \n");
    afficherARBPreOrder(root);
    printf("\nOK!\n");
    printf("Test InOrderTraversal \n");
    afficherARBInOrder(root);
    printf("\nOK!\n");
    printf("Test PostOrderTraversal \n");

    afficherARBPostOrder(root);
    printf("\nOK!\n");



    printf("Test suppression (donc RotD, RotG et Rechercher): \n");
    printf("Topo Arbre avant suppression: \n");
    afficherARBTopo(root, 2);

    printf("Test suppression d'un élémént non-existant: ");
    Supprimer(root, 10);
    assert( !Rechercher(root, 10));
    printf("OK!\n");

    printf("Test suppression d'un élémént existant: ");
    Supprimer(root, 7);
    assert( !Rechercher(root, 7));
    printf("OK!\n");

    printf("\n Topo arbre après suppression de 10 \n");
    afficherARBTopo(root, 2);

    return EXIT_SUCCESS;
}
