#include <bits/stdc++.h> 

void finduniqueSubsets(int n, vector<int> &arr, int index, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);

    for(int i=index;i<n;i++){
        if(i>index && arr[i] == arr[i-1]){
            continue;
        }
        
        ds.push_back(arr[i]);
        finduniqueSubsets(n, arr, i+1, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    int index=0;
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    finduniqueSubsets(n, arr, index, ds, ans);
    return ans;
}
