#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class NodeValue{
    public:
    int minVal, maxVal, maxSize;
    NodeValue(int minV,int maxV,int maxS){
        minVal = minV;
        maxVal = maxV;
        maxSize = maxS; 
    }
};

NodeValue largestBSTHelper(TreeNode<int>* root){
    if(root==NULL){
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
    
    NodeValue leftST = largestBSTHelper(root->left);
    NodeValue rightST = largestBSTHelper(root->right);
    
    if(root->data > leftST.maxVal && root->data < rightST.minVal){
        return NodeValue(min(root->data, leftST.minVal), max(root->data, rightST.maxVal), 1+leftST.maxSize+rightST.maxSize);
    }

    return NodeValue(INT_MIN, INT_MAX, max(leftST.maxSize, rightST.maxSize));
}

int largestBST(TreeNode<int>* root) 
{
    if(root==NULL){
        return 0;
    }
    return largestBSTHelper(root).maxSize;
}
