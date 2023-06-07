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

int dia(TreeNode<int> *root, int& ans){
    if(root==NULL){
        return 0;
    }
    
    int ls = dia(root->left, ans);
    int rs = dia(root->right, ans);

    ans = max(ans, ls+rs);      
    
    return 1+max(ls, rs);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int ans=0;
    if(root==NULL){
        return ans;
    }
    dia(root, ans);
    return ans;
}
