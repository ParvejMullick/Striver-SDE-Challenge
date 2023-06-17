#include<bits/stdc++.h>
int solve(vector<int> &val, vector<int> &wt, int index, int W, vector<vector<int>>& dp){
    if(index==0){
        if(wt[0]<=W){
            return val[0];
        }
        return 0;
    }

    if(dp[index][W] != -1){
        return dp[index][W];
    }
    
    int notTake = solve(val, wt, index-1, W, dp);
    int take = INT_MIN;
    if(W>=wt[index]){
        take = val[index]+solve(val, wt, index-1, W-wt[index], dp);
    }
    return dp[index][W] = max(take, notTake);
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{   
   vector<int> curr(w+1, 0);
    for(int i=weights[0];i<=w;i++){
        curr[i] = values[0];
    }

    for(int i=1;i<n;i++){
        for(int j=w;j>=0;j--){
            int notTake = curr[j];
            
            int take = INT_MIN;
            if(j>=weights[i]){
                take = values[i]+curr[j-weights[i]];
            }

            curr[j] = max(take, notTake);
        }
    }
    return curr[w];
}
