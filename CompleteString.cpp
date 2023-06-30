#include <bits/stdc++.h> 

class Node{
    Node* links[26];
    bool flag = false;
    
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

    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag==true;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==false){
                node->put(word[i], new Node());
            }
            node= node->getChild(word[i]);
        }
        node->setEnd();
    }

    bool isComp(string& s){
        Node* node = root;
        for(int i=0;i<s.size();i++){
            node=node->getChild(s[i]);
            if(node->isEnd()==false){
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    
    for(auto i:a){
        trie.insert(i);
    }
    
    string ans = "";
    for(int i=0;i<n;i++){
        if(trie.isComp(a[i])){
            if(a[i].size()>ans.size()){
                ans = a[i];
            }
            else if(a[i].size()==ans.size() && a[i]<ans){
                ans = a[i];
            }
        }
    }

    if(ans==""){
        return "None";
    }
    return ans;
}
