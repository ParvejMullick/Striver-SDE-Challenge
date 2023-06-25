#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int> dp(n , 0);
    dp[0] = rack[0];
    
    for(int i=1;i<n;i++){
        int maxSumSubseq = rack[i];
        for(int j=0;j<i;j++){
          if (rack[i] > rack[j]) {
            maxSumSubseq = max(maxSumSubseq, rack[i]+dp[j]);
          }
        }
        dp[i] = maxSumSubseq;
    }
    
    int ans = *max_element(dp.begin(), dp.end());
    return ans;
}
