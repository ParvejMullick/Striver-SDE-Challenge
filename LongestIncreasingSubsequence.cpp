#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }
    return temp.size();
}
