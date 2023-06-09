#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    BinaryTreeNode< int > * firstNode=root;
    
    while( firstNode != NULL){
        BinaryTreeNode< int > * oneLevelAbove = firstNode;
        BinaryTreeNode< int > * prev = NULL;
        firstNode=NULL;
        
        while(oneLevelAbove != NULL){
            
            if(oneLevelAbove->left != NULL){
                if(prev != NULL){
                    prev->next = oneLevelAbove->left;
                }
                
                if(firstNode==NULL){
                    firstNode=oneLevelAbove->left;
                }
                prev = oneLevelAbove->left;
            }
            
            
            if(oneLevelAbove->right != NULL){
                if(prev !=NULL){
                    prev->next=oneLevelAbove->right;
                }

                if(firstNode==NULL){
                    firstNode = oneLevelAbove->right;
                }
                
                prev = oneLevelAbove->right;
            }
             oneLevelAbove = oneLevelAbove->next;
        }
        
    }
}
