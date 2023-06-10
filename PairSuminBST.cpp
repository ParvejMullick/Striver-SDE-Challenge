#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

class BSTIterator{
    public:
    
    stack<BinaryTreeNode<int> *> st;
    bool flag;

    BSTIterator(BinaryTreeNode<int> *root, bool goNext){
        flag = goNext;
        pushAll(root);
    }

    int next(){
        BinaryTreeNode<int> *temp=st.top();
        st.pop();
        
        if(flag==true){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        
        return temp->data;
    }
    
    void pushAll(BinaryTreeNode<int> *root){
        BinaryTreeNode<int> *temp = root;
        while(temp){
            st.push(temp);
            if(flag==true){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
    }
};


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(root==NULL){
        return false;
    }
    
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    
    int i=r.next();
    int j=l.next();
    
    while(i<j){
        if(i+j>k){
            j=l.next();
        }
        else if(i+j<k){
            i=r.next();
        }
        else{
            return true;
        }
    }
    return false;
}
