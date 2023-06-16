#include <bits/stdc++.h> 

bool solve(int index, int target, vector<int>&arr, vector<vector<int>>& dp){
    if(target==0){
        return true;
    }
    if(index==0){
        return arr[index]==target;
    }
    
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    
    bool notTake = solve(index-1, target, arr, dp);
    bool take = false;
    if(target>=arr[index]){
        take = solve(index-1, target-arr[index], arr, dp);
    }
    return dp[index][target]=notTake | take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1, false);
    prev[0] = true;
    if(k>=arr[0]){
        prev[arr[0]] = true;
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            bool take = false;
            if(j>=arr[i]){
                take = prev[j-arr[i]];
            }
            bool notTake=prev[j];
            curr[j] = take | notTake;
        }
        prev = curr;
    }
    return prev[k];
}
