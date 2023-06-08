#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int findMax(long long int data1, long long int data2){
    if(data1>data2){
        return data1;
    }
    
    return data2;
}

long long int pathSum(TreeNode<int> *root, long long int& ans){
    if(root==NULL){
        return 0;
    }
    
    long long int leftST = findMax(0, pathSum(root->left, ans));
    long long int rightST = findMax(0, pathSum(root->right, ans));
    
    ans = findMax(ans, leftST+rightST+root->val);
    
    return root->val + findMax(leftST, rightST);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==NULL || root->left==NULL || root->right==NULL){
        return -1;
    }
    long long int ans=0;
    pathSum(root, ans);
    return ans;
}
