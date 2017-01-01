#ifndef __struct_h
#define __struct_h




struct __boxType{
    char O[21];
    int H;
    int W;
    int D;
    int V;
};
typedef struct __boxType element;

typedef struct __treeType* tree;
struct __treeType{
    tree left;
    tree right;
    element e;
    int height;
};


//--------------------TREE DISPLAY FUNCTIONS
void preOrder (tree);
void postOrder (tree);
void inOrder (tree);
void displayNode (element); //non recursive

//--------------------TREE INTERFACE FUNCTIONS
tree addNode(tree, int, int, int, char*);
int size(tree);
tree removeNode(tree, element);
void clearTree(tree);
element newElement(int, int, int, char*);

#endif