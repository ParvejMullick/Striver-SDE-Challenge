#include <bits/stdc++.h> 

void findpermute(string &s, vector<string>& res, int index){
    if(index==s.size()){
        res.push_back(s);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        swap(s[i], s[index]);
        findpermute(s, res, index+1);
        swap(s[i], s[index]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> res;
    int index=0;
    findpermute(s, res, index);
    return res;
}
