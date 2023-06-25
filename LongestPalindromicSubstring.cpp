#include<bits/stdc++.h>

string expand(int left, int right, string& s){
    int n= s.size();
    while(left>=0 && right<n){
        if(s[left] != s[right]){
            break;
        }
        
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}

string longestPalinSubstring(string str)
{
    string ans="";
    int n=str.size();
    string oddLen="";
    for(int i=0;i<n;i++){
        oddLen = expand(i, i, str);
        if(ans.size()<oddLen.size()){
            ans = oddLen;
        }
    }
    
    string evenLen = "";
    for(int i=0;i<n;i++){
        evenLen = expand(i, i+1, str);
        if(ans.size()<evenLen.size()){
          ans = evenLen;
        }
    }
    return ans;
}
