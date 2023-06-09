#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *kthS(TreeNode<int> *root, int& k){
    if(root==NULL){
        return NULL;
    }
    
    TreeNode<int> *leftST = kthS(root->left, k);
    if(leftST != NULL){
        return leftST;
    }
    
    k--;
    if(k==0){
        return root;
    }
    return kthS(root->right, k);
}



int kthSmallest(TreeNode<int> *root, int k)
{
	TreeNode<int> *temp= kthS(root, k);
    return temp->data;
}
