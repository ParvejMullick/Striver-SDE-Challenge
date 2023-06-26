#include<bits/stdc++.h>

int solve(int axe, int cap, vector<vector<int>>& dp){
    if(axe==1){
        return cap;
    }
    if(cap<=1){
        return cap;
    }
    if(dp[axe][cap] != -1){
        return dp[axe][cap];
    }
    
    int mini = 1e9;
    int low = 1;
    int high = cap;
    while(low<=high){
        int mid = low + (high-low)/2;
        
        int logCut = solve(axe, cap-mid, dp);
        int logUncut = solve(axe-1, mid-1, dp);
        
        int temp = 1 + max(logCut, logUncut);
        mini = min(mini, temp);
        
        if(logCut>logUncut){
           low = mid+1; 
        }
        else{
            high = mid-1;
        }
}

        return dp[axe][cap] = mini;
}

int cutLogs(int k, int n)
{
    vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
    return solve(k, n, dp);
}
