#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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

bool isLeaf(TreeNode<int>* root){
    if(root->left || root->right){
    return false;
    }
    return true;
    }
    
    void addLeftBoun(vector <int>& ans, TreeNode<int>*root){
        TreeNode<int>* curr = root->left;
        while(curr != NULL){
            if( !isLeaf(curr) ){
                ans.push_back(curr->data);
            }
            if(curr->left){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
    }

void addLeaves(vector <int>& ans, TreeNode<int>*root){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        
        if(root->left){
            addLeaves(ans, root->left);
        }
        if(root->right){
            addLeaves(ans, root->right);
        }
    }

void addRightBoun(vector <int>& ans, TreeNode<int>*root){
        TreeNode<int>* curr = root->right;
        stack<int> temp;
        
        while(curr != NULL){
            if( !isLeaf(curr)){
                temp.push(curr->data);
            }
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        
        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }
    }

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    if(!isLeaf(root)){
            ans.push_back(root->data);
    }
    addLeftBoun(ans, root);
    addLeaves(ans, root);
    addRightBoun(ans, root);
    return ans;
}
