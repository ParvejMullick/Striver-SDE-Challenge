#include <bits/stdc++.h> 

bool isPalindrome(int s, int e, string& str){
   while(s<e){
      if(str[s++] != str[e--]){
         return false;
      }
   }
   return true;
}


int solve(string& s, int index, int n, vector<int>& dp){
   if(index==n){
      return 0;
   }
   
   if(dp[index] != -1){
      return dp[index];
   }
   
   int mini = INT_MAX;
   for(int i=index;i<n;i++){
      if(isPalindrome(index, i, s)==true){
         int palindrome = 1+ solve(s, i+1, n, dp);
         mini = min(mini, palindrome);
      }
   }
   return dp[index] = mini;
}

int palindromePartitioning(string str) {
   int index = 0;
   int n = str.size();
   // vector<int> dp(n , -1);
   //  return solve(str, index, n, dp)-1;
   
   vector<int> dp(n+1 , 0);
  for(int i=n-1;i>=0;i--){
     int mini = INT_MAX;
     for(int j=i;j<n;j++){
        if(isPalindrome(i, j, str)==true){
           int palindrome = 1 + dp[j+1];
           mini = min(mini, palindrome);
        }
     }
     dp[i] = mini;  
  }
   return dp[0]-1;
}
