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

int getMaxWidth(TreeNode<int> *root)
{
    int ans=0;
    if(root==NULL){
        return 0;
    }

    queue<TreeNode<int>*> q;
    q.push(root);
     
    while(!q.empty()){
        int size = q.size();
        ans = max(ans, size);
        
        for(int i=0;i<size;i++){
            auto temp = q.front();
            q.pop();
        
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
           
        }
    }
    return ans;
}
