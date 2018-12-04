#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ntree.h"

#include <stdbool.h>
#include "min-max.h"

NTree ntree_create(const void *data, size_t size, size_t arity)
{
    NTree tree = (NTree)malloc(sizeof(NTree *) + sizeof(size_t) + size);
    if (tree)
    {
        tree->subtrees = (NTree *)malloc( sizeof(arity) * sizeof(NTree));
        if (tree->subtrees)
        {

            for(size_t i = 0; i < arity; i++){
                tree->subtrees[i] = NULL;
            }

            tree->arity = arity;
            memcpy(tree->data, data, size);
        }
    }
    else
    {
        free(tree);
        tree = NULL;
    }

    return tree;
}

void ntree_delete(NTree tree, void (*delete)(void *))
{
    NTree subtree;
    if (tree)
    {
        if (delete)
        {
            delete (tree->data);
        }
        for (size_t i = 0; i < tree->arity; i++)
        {
            ntree_delete(tree, *delete);
        }
        free(tree);
    }
}

NTree ntree_get_nth(NTree tree, size_t nth)
{
    if (tree)
    {
        return tree->subtrees[nth];
    }
    return NULL;
}

void *ntree_get_data(NTree tree)
{
    if (tree)
    {
        return tree->data;
    }
    return NULL;
}

int ntree_set_nth(NTree tree, NTree sub, size_t nth)
{
    if (tree)
    {
        if (nth+1 <= tree->arity)
        {
            tree->subtrees[nth] = sub;
            return true;
        }
    }
    return false;
}

int ntree_set_data(NTree tree, const void *data, size_t size)
{
    if (tree)
    {
        memcpy(tree->data, data, size);
        return true;
    }
    return false;
}

void ntree_pre_order(NTree tree,
                     void (*func)(void *, void *),
                     void *extra_data)
{
    // Root -> left -> right
    // func = monPrintf(void* a, void* b)
    if(tree){
        func(tree->data, NULL);
        for(size_t i = 0; i < tree->arity; i++){
            ntree_pre_order(tree->subtrees[i], func, extra_data);
        }
    }
}

void ntree_in_order(NTree tree,
                    void (*func)(void *, void *),
                    void *extra_data,
                    size_t nth)
{
    // left -> root -> right
    if(tree && nth+1 <= tree->arity){
        for(size_t i = 0; i < nth; i++){
            ntree_in_order(tree->subtrees[i], func, extra_data, nth);
        }

        func(tree->data, extra_data);

        for(size_t i = nth; i < tree->arity; i++){
            ntree_in_order(tree->subtrees[i], func, extra_data, nth);
        }
    }
}

void ntree_post_order(NTree tree,
                      void (*func)(void *, void *),
                      void *extra_data)
{
    // left -> right -> root
    if(tree){
        for(size_t i = 0; i < tree->arity; i++){
            ntree_post_order(tree->subtrees[i], func, extra_data);
        }
        func(tree->data, extra_data);
    }
}

size_t ntree_height(NTree tree)
{
    if(tree)
    {
        if(tree->subtrees)
        {
            size_t res = 1;

            switch(tree->arity){
                case 0:
                    return 1;
                case 1:
                    res += ntree_height(tree->subtrees[0]);
                    break;
                default:
                    for(size_t i=0; i < tree->arity; i++)
                    {
                        size_t child = 1 + ntree_height(tree->subtrees[i]);
                        res = MAX(res, child);
                    }
                    break;
            }

            //printf("Résultat ntree_height(): %ld\n", res);
            return res;
        }
        return 1;
    }
    return 0;
}

size_t ntree_size(NTree tree)
{
    if (tree)
    {
        if(tree->subtrees){
            size_t res = 1;
            for (size_t i = 0; i < tree->arity; i++)
            {
                res += ntree_size(tree->subtrees[i]);
            }

            //printf("Résultat ntree_size(): %ld\n", res);
            return res;
        }
    }

    return 0;
}
