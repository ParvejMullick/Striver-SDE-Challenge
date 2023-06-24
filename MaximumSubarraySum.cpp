#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = arr[0];
    long long maxi = LONG_MIN;
    for(int i=1;i<n;i++){
        long long temp = arr[i];
        sum = max(temp, temp+sum);
        maxi = max(maxi, sum);
    }
    
    if(maxi<0){
        return 0;
    }
    return maxi;
}
