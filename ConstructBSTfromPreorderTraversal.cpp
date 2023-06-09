#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* buildTree(vector<int> &preOrder, int& index, int bound){
    if(index==preOrder.size() || preOrder[index]>bound){
        return NULL;
    }
    
    TreeNode<int>* root=new TreeNode<int>(preOrder[index]);
    index++;
    
    root->left = buildTree(preOrder, index, root->data);
    root->right = buildTree(preOrder, index, bound);
    return root;
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int ind=0;
    int bound=INT_MAX;
    return buildTree(preOrder, ind, bound);
}
