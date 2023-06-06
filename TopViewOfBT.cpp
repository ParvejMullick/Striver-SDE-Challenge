#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL){      
        return ans;
    }
    
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        
        TreeNode<int> *node= temp.first;
        int hl = temp.second;
        if(mp.find(hl)==mp.end()){
            mp[hl] = node->val;
        }

        if(node->left){
            q.push({node->left, hl-1});
        }
        if(node->right){
            q.push({node->right, hl+1});
        }
    }
    
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
