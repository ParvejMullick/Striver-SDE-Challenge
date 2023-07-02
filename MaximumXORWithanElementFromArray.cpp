#include<bits/stdc++.h>

class Node{
    Node* links[2];
    public:
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* getChild(int bit){
        return links[bit];
    }

};

class Trie{
    Node* root;
    public:
    
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(bit)==false){
              node->put(bit, new Node());
            }
            node=node->getChild(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxXor = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)==true){
                maxXor = maxXor | (1<<i);
                node = node->getChild(1-bit);
            }
            else{
                node = node->getChild(bit);
            }
        }
        return maxXor;
    }
};


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> offlineQ;
    int q= queries.size();
    int n=arr.size();
    for(int i=0;i<q;i++){
        offlineQ.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(offlineQ.begin(), offlineQ.end());
    int ind=0;
    
    vector<int> ans(q, 0);
    Trie trie;
    for(int i=0;i<q;i++){
        int ai = offlineQ[i].first;
        int xi = offlineQ[i].second.first;
        int qInd = offlineQ[i].second.second;
        while(ind<n && arr[ind]<=ai){
            trie.insert(arr[ind]);
            ind++;
        }
        if(ind==0){
            ans[qInd] = -1;
        }
        else{
            ans[qInd] = trie.getMax(xi);
        }
    }
    return ans;
}
