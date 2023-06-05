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

void lview(vector<int>& res, int level, TreeNode<int> *root){
    if(root==NULL){
        return;
    }
    
    
    if(level == res.size()){
        res.push_back(root->data);
    }

    lview(res, level+1, root->left);
    lview(res, level+1, root->right);
    
}

vector<int> getLeftView(TreeNode<int> *root)
{   
    vector<int> res;
    if(root==NULL){
        return res;
    }
    
    int level=0;
    lview(res, level, root);
    return res;
}
