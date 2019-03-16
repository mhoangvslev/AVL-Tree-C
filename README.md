# AVL-Tree-C
Basic implementation of various type of search tree. Configured with CMakeUI and edited with CodeBlock

- build
- src
- tmp: the packaged files dor distribution

## N-ary tree
A N-ary tree is a rooted tree in which each node has no more than N children

## AVL tree
An AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree

## Red-Black tree
A red–black tree is a kind of self-balancing binary search tree in computer science
- 2 test files : 
	+ Console display : test-TreeRB.c
	+ GUI display : test-TreeRBIHM.c
	+ Load test: test-TreeRB-exectime

- OpenGL GLUT is required: ```sudo apt-get install freeglut3-dev```

- Test by simply compile and execute:

```bash
make test-TreeRB
./test-TreeRB                # pour executer les test de l'arbre

make test-TreeRBIHM
./test-TreeRBIHM             # pour le dessin de l'arbre (avec IHM textuelle)

make test-TreeRB-exectime
./test-TreeRB-exectime       # temps d'éxécution avec différentes tailles d'arbre
```
## Démonstration
executer le script ```cmake_TreeRB.sh```: ```sh cmake_TreeRB.sh```
