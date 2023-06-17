#include <bits/stdc++.h> 
int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>>& dp){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
        return 1e8;
    }
    if(i==0 && j==0){
        return grid[0][0];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int up = grid[i][j]+solve(grid, i-1, j, dp);
    int left = grid[i][j]+solve(grid, i, j-1, dp);
    
    return dp[i][j]=min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<int> prev(n, 0), curr(n, 0);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                curr[j] = grid[i][j];
            }
            else{
                int up = grid[i][j];
                if(i-1>=0){
                    up += prev[j];
                }
                else{
                    up += 1e8;
                }
                int left = grid[i][j];
                if(j-1>=0){
                    left += curr[j-1];
                }
                else{
                    left += 1e8;
                }
                curr[j] = min(up, left);
            }
        }
        prev=curr;
    }
    return prev[n-1];
}
