#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* buildTree(vector<int> &arr, int st, int ed){
    if(st > ed){
        return NULL;
    }
    
    int mid = ed - (ed - st)/2;
    
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    
    root->left = buildTree(arr, st, mid-1);
    root->right = buildTree(arr, mid+1, ed);

    return root;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n==0){
        return NULL;
    }
    
    TreeNode<int>* root = buildTree(arr, 0, n-1);
    return root;
}
