#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    stack<TreeNode*> st;
    TreeNode* temp = root;
    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()==true){
                break;
            }
            
            temp = st.top();
            st.pop();
            
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    
    return ans;
}
