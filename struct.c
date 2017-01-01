#include "struct.h"
#include "stdlib.h"
#include <string.h>
#include <stdio.h>

//This will change when I implement the box feature.



int height(tree t){
    if(t == NULL){
        return 0;
    }
    return t->height;
}

int compare(element n, element m){
    if(n.V > m.V){
        return 1; // returns 1 if the left is greater than the right;
    }else if(n.V < m.V){
        return -1;
    }else{
        return 0;
    }
}

tree recalcHeight(tree t){
    if(t != NULL){

      if(height(t->left) > height(t->right)) {
          t->height = height(t->left) + 1;
      }
      else {
          t->height = height(t->right) + 1;
      }
    }
    return t;
}


tree rotateRight(tree t){
    if(t == NULL) return t;
    if(t->left == NULL) return t;

    tree newRoot = t->left;
    t->left = newRoot->right;
    newRoot -> right = t;
    
    recalcHeight(t);
    recalcHeight(newRoot);
    return newRoot;
}

tree rotateLeft(tree t){
    if(t == NULL)return t;
    if(t->right == NULL) return t;
    tree newRoot = t->right;
    t->right = newRoot->left;
    newRoot->left = t;

    recalcHeight(t);
    recalcHeight(newRoot);
    return newRoot;
}

element max(element n, element m){
    element maxElement;
    if(compare(n, m)){
        return n;
    }else{
        return m;
    }
}

tree rebalance(tree t){

    if(t == NULL)return t;
    if(height(t->left) > height(t->right) + 1){
        if(height(t->left->right)>height(t->left->left)){
            t->left = rotateLeft(t->left);
        }
            return rotateRight(t);
    }else if(height(t->right) > height(t->left) + 1){
                if(height(t->right->left) > height(t->right->right)){
                    t->right = rotateRight(t->right);
                }
                return rotateLeft(t);
            }
    recalcHeight(t);
    return t;
}



void displayNode(element e){
  printf("Box(H = %d, W = %d, D = %d, A = %d, O = %s)\n", e.H, e.W, e.D, e.V, e.O);
}

void preOrder(tree t){ //Make sure the order is correct, but this will be the pattern for the rest of the display functions.
    if(t == NULL) return;
    displayNode(t->e);
    preOrder(t->left);
    preOrder(t->right);
}
void postOrder(tree t){
    if(t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    displayNode(t->e);
}
void inOrder(tree t){
    if(t == NULL) return;
    inOrder(t->left);
    displayNode(t->e);
    inOrder(t->right);
}


element newElement(int h, int w, int d, char owner[21]){
    element E;
    strcpy(E.O, owner);
    E.H = h;
    E.W = w;
    E.D = d;
    E.V=h*w*d;
    return E;
}

tree newTree(int h, int w, int d, char owner[21]){
    tree T = (tree)malloc(sizeof(struct __treeType));
    T -> e = newElement(h,w,d,owner);
    T -> left = NULL;
    T -> right = NULL;
    T -> height = 1;
    return T;
}

tree addNode(tree t, int h, int w, int d, char owner[21]){ //This will need to change to analyze the left instead.
    tree nTree = newTree(h,w,d,owner); 
    if(t == NULL){
        t = nTree;
    }else if(compare(nTree->e, t->e) == -1){
        t->left = addNode(t->left, h,w,d, owner);
    }else{
        t->right = addNode(t->right, h,w,d,owner);
    }return rebalance(t);
}

tree removerHelper(tree n, tree m){
    if(n == NULL) return n;
    if(n -> right != NULL){
        n->right = removerHelper(n->right, m);
        return rebalance(n);
    }else{
        m->e = n->e;
        tree left = n->left;
        free(n);
        return left;
    }
}



tree removeNode(tree t, element e){
    if(t == NULL) return t;

    if(compare(t->e, e) > 0){
        t->left = removeNode(t->left, e);
    }else if(compare(t->e,e) < 0){
        t->right = removeNode(t->right, e);
    }else{
        if(t->left == NULL){
            tree newRoot = t->right;
            free(t);
            return newRoot;
        }else{
            t->left = removerHelper(t->left, t);
        }
    }
    return rebalance(t);
}



int count (tree t, element e){
    if(t == NULL) return 0;
   if(compare(t->e,e) > 0){
       return count(t->left,e);
   }else if (compare(t->e,e) < 0){
       return count(t->right,e);
       }
       else{
           return 1 + count(t->left,e) + count(t->right,e);
       }
}