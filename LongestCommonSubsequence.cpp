#include<bits/stdc++.h>
int solve(int index1, string& s, int index2, string& t, vector<vector<int>>& dp){
    if(index1==0 || index2==0){
        return 0;
    }

    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }
    if(s[index1-1]==t[index2-1]){
        return dp[index1][index2] = 1+solve(index1-1, s, index2-1, t, dp);
    }
    
    else{
        return dp[index1][index2] = max(solve(index1-1, s, index2, t, dp), solve(index1, s, index2-1, t, dp));
    } 
}

int lcs(string s, string t)
{
	int m= s.size();
    int n= t.size();
    
    // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    // return solve(m, s, n, t, dp);
    
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int i=0;i<=n;i++){
        prev[i] = 0;
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                curr[j] = 1 + prev[j-1];
            }
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}
