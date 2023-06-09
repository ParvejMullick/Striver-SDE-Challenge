#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* kthL(TreeNode<int>* root, int& k){
    if(root==NULL){
        return NULL;
    }
    
    TreeNode<int>* rs = kthL(root->right, k);
    if(rs != NULL){
        return rs;
    }
    
    k--;
    
    if(k==0){
        return root;
    }
    
    return kthL(root->left, k);
    
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    TreeNode<int>* ans = kthL(root, k);
    if(ans==NULL){
        return -1;
    }
    else{
        return ans->data;
    }
}
