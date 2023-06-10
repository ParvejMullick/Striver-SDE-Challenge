#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* curr1=root;
    BinaryTreeNode<int>* curr2=root;
    
    int pre=-1;
    int suc=-1;
    
    while(curr1 || curr2){
        if(curr1 && curr1->data>=key){
            curr1=curr1->left;
        }
        else if(curr1){
            pre = curr1->data;
            curr1=curr1->right;
        }
        
        if(curr2 && curr2->data <= key){
            curr2=curr2->right;
        }
        else if(curr2){
            suc=curr2->data;
            curr2=curr2->left;
        }
    }
    
    return {pre, suc};
}
