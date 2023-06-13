#include <bits/stdc++.h> 

bool isPalindrome(string &s, int start, int end){
    while(start<=end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void solve(string &s, vector<string>& temp, vector<vector<string>>& ans, int index){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s, index, i)){
            temp.push_back(s.substr(index, i-index+1));
            solve(s, temp, ans, i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<string> temp;
    vector<vector<string>> ans;
    int index=0;
    solve(s, temp, ans, index);
    return ans;
}
