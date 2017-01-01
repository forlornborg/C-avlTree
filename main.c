#include <stdio.h>
#include "struct.h"
#include <string.h>




int main(){
    char command[81];
    tree root = NULL;
    int H;
    int W;
    int D;
    char O[21];

    while( scanf("%s",command) >0){
        if(strcmp(command,"Add") == 0){
            element e;
            scanf("%d %d %d %s", &H, &W, &D, O);
            root = addNode(root, H, W, D, O);
        }
        else if(strcmp(command, "Inorder") == 0){
            printf("Inorder:\n");
            inOrder(root);
        }
        else if(strcmp(command, "Preorder") == 0){
            printf("Preorder:\n");
            preOrder(root);
        }
        else if(strcmp(command, "Postorder") == 0){
            printf("postOrder:\n");
            postOrder(root);
        }
        else if(strcmp(command, "Remove") == 0){
            int toRemove;
            scanf("%d", &toRemove);
            element toRemoveElement = newElement(1,1,toRemove, "");
            root = removeNode(root, toRemoveElement);
        }else if (strcmp(command, "Count") == 0){
            int counter;
            scanf("%d",&counter);
            element toCountElement = newElement(1,1,counter, "");
            printf("There are %d boxes with volume of %d.\n",count(root, toCountElement),counter);
        }else if (strcmp(command, "RemoveAll") == 0){
            int toRemoveAll;
            scanf("%d",&toRemoveAll);
            element toRemoveAllElement = newElement(1,1,toRemoveAll,"");
            int numToRemove = count(root,toRemoveAllElement);
            int j = 0;
            for(;j<numToRemove;j++){
                removeNode(root, toRemoveAllElement);
            }
        }
        
    }
}