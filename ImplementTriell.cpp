#include <bits/stdc++.h>

class Node{
    Node* links[26];
    int prefCount=0;
    int wordCount=0;
    
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
    
     void increasePrefCount(){
         prefCount++;
     }
    
    void increaseWordCount(){
        wordCount++;
    }

    int getWordCount(){
      return wordCount;   
    }

    int getPrefCount(){
        return prefCount;
    }

    void decreasePrefCount(){
        prefCount--;
    }

    void decreaseWordCount(){
        wordCount--;
    }

};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==false){
                node->put(word[i], new Node()); 
                
            }
            node=node->getChild(word[i]);
             node->increasePrefCount();
        }
        node->increaseWordCount();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==true){
                node=node->getChild(word[i]);
            }
            else{
               return 0; 
            }
        }
        return node->getWordCount();
    } 

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])==true){
                node = node->getChild(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefCount();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i]) == true){
                node = node->getChild(word[i]);
                 node->decreasePrefCount();
            }
            else{
               return ; 
            }
    }
         node->decreaseWordCount();
    }
};
