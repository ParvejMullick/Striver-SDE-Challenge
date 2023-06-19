class Solution {
public:
    
    int solve(int i, string& s1, int j, string& s2, vector<vector<int>> &dp){
        if(i==0){
            return j;
        }
        if(j==0){
            return i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i-1]==s2[j-1]){
            return dp[i][j] = solve(i-1, s1, j-1, s2, dp);
        }
        else{
            return dp[i][j] = 1 + min(solve(i, s1, j-1, s2, dp), min(solve(i-1, s1, j, s2, dp), solve(i-1, s1, j-1, s2, dp)));
        }
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int j=0;j<=n;j++){
            prev[j] = j;
        }
        
        for(int i=1;i<=m;i++){
            curr[0] = i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1 + min(curr[j-1], min(prev[j], prev[j-1]));
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
