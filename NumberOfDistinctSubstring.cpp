#include <bits/stdc++.h> 

class Node{
    Node* links[26];
    
    public:
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* getChild(char ch){
        return links[ch-'a'];
    }
};

int distinctSubstring(string &word) {
    int n = word.size();
    int count=0;
    Node* root=new Node();
    for(int i=0;i<n;i++){
        Node* node = root;
        for(int j=i;j<n;j++){
            if(node->containsKey(word[j])==false){
                count++;
                node->put(word[j], new Node());
            }
            node = node->getChild(word[j]);
        }
    }
    return count;
}
