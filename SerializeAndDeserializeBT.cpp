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
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
      string res="";
        if(root==NULL){
            return res;
        }
        queue<TreeNode<int> *> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode<int> * node = q.front();
            q.pop();
            
            if(node==NULL){
                res.append("#,");
            }
            else{
                res += to_string(node->data)+',';
            }
            
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        
         return res;

}

TreeNode<int>* deserializeTree(string &serialized)
{
     if(!serialized.size()) return NULL;
		stringstream s(serialized);
		string str;
		getline(s,str,',');
		TreeNode<int>* root= new TreeNode<int>(stoi(str)); 
		queue<TreeNode<int>*>q;
		q.push(root);
		while(!q.empty()){
			TreeNode<int>* node=q.front();
			q.pop();

			getline(s,str,',');
			if(str=="#") node->left=NULL;
			else{
				node->left=new TreeNode<int>(stoi(str));
				q.push(node->left);
			}

			getline(s,str,',');
			if(str=="#") node->right=NULL;
			else{
				node->right=new TreeNode<int>(stoi(str));
				q.push(node->right);
			}
		}
		return root;
}



