int solve(vector<int> &price, int index, int rodLen, vector<vector<int>>& dp){
    if(index==0){
        return rodLen*price[0];
    }

if(dp[index][rodLen] != -1){
    return dp[index][rodLen];
}
    
    int notTake = solve(price, index-1, rodLen, dp);
    int take = INT_MIN;
    int cutLen = index+1;
    if(cutLen<=rodLen){
        take = price[index]+solve(price, index, rodLen-cutLen, dp);
    }
    return dp[index][rodLen]= max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{   
    vector<int> curr(n+1, 0);
    
    for(int i=0;i<=n;i++){
       curr[i] = i*price[0];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int notTake = curr[j];
            int take =INT_MIN;
            int cutLen = i+1;
            if(j>=cutLen){
                take = price[i] + curr[j-cutLen];
            }
            curr[j] = max(take, notTake);
        }
    }
    return curr[n];
}
