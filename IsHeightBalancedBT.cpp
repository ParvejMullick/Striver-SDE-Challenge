#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int isBalanced(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    int leftST = isBalanced(root->left);
    if(leftST==-1){
        return -1;
    }

    int rightST = isBalanced(root->right);
    if(rightST==-1){
        return -1;
    }
    
    if(abs(leftST - rightST)>1){
        return -1;
    }

    return 1+max(leftST, rightST);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return isBalanced(root) != -1;
}
