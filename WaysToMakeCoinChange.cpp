#include<bits/stdc++.h>
long solve(int *arr, int index, int x, vector<vector<long>>& dp){
    if(index==0){
        return x%arr[0]==0;
    }

    if(dp[index][x] != -1){
        return dp[index][x];
    }
    
    long notTake = solve(arr, index-1, x, dp);
    long take = 0;
    if(x>=arr[index]){
        take = solve(arr, index, x-arr[index], dp);
    }
    
    return dp[index][x]= take+notTake;
}

long countWaysToMakeChange(int *arr, int n, int value)
{ 
    vector<long> curr(value+1, 0);
    for(int i=0;i<=value;i++){
        curr[i] = (i%arr[0]==0);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=value;j++){
            long notTake = curr[j];
            long take=0;
            if(j>=arr[i]){
                take = curr[j-arr[i]];
            }
            curr[j] = take+notTake;
        }
    }
    return curr[value];

}
