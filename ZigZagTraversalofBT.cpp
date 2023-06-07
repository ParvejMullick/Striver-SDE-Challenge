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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        
        int size=q.size();
        
        vector<int> v(size);
        for(int i=0;i<size;i++){
            auto temp = q.front();
            q.pop();
            
            int ind=flag ? i : size-i-1;
            
            v[ind] = temp->data;
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }  
        }
        flag = !flag;
        ans.insert(ans.end(), v.begin(), v.end());
    }
    return ans;
}
