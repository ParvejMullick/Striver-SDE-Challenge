/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool isSym(BinaryTreeNode<int>* ls, BinaryTreeNode<int>* rs){
    if(ls==NULL || rs==NULL){
        return ls==rs;
    }
    
    return (ls->data == rs->data) && isSym(ls->left, rs->right) && isSym(ls->right, rs->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{   
    if(root==NULL){
        return true;
    }
    return isSym(root->left, root->right);    
}
