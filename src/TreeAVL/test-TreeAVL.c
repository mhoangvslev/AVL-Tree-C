#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "TreeAVL.h"



int main()
{
    AVL root = NULL;

    printf("Test insertion (donc RotD, RotG): \n");

    root = Ajouter(9, root);
    assert(root->value == 9);

    root = Ajouter(5, root);
    assert(root->childLeft->value == 5);

    root = Ajouter(10, root);
    assert(root->childRight->value == 10);
    assert(hauteur(root) == 2);

    root = Ajouter(0, root);
    assert( root->childLeft->childLeft->value == 0 );

    root = Ajouter(6, root);
    assert( root->childLeft->childRight->value == 6 );

    root = Ajouter(11, root);
    assert( root->childRight->childRight->value == 11 );

    root = Ajouter(-1, root);
    assert( root->childLeft->childLeft->childLeft->value = -1 );

    root = Ajouter(1, root);
    assert( root->childLeft->childLeft->childRight->value = 1 );

    root = Ajouter(2, root);
    assert( root->childLeft->childRight->childLeft->value = 2 );

    printf("OK!\n");

    printf("Test Noeuds: \n");
    assert( Noeuds(root) == 9 );
    printf("OK!\n");

    printf("Test PreOrderTraversal \n");
    afficherAVLPreOrder(root);  printf("\nOK!\n");
    afficherAVLInOrder(root);  printf("\nOK!\n");
    afficherAVLPostOrder(root);  printf("\nOK!\n");

    printf("Test suppression (donc RotD, RotG et Rechercher): \n");
    printf("Pre-order avant suppression: \n");
    afficherAVLTopo(root, 2);

    root = Supprimer(10, root);
    assert( ! Rechercher(10, root));
    printf("OK!\n");

    printf("\n Pre-order après suppression de 10 \n");
    afficherAVLTopo(root, 2);

    return EXIT_SUCCESS;
}
