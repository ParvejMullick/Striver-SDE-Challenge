#include<bits/stdc++.h>
void findCombSum2(vector<int> &arr, int n, int target, vector<int>& ds, vector<vector<int>>& ans, int index){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        
        ds.push_back(arr[i]);
        findCombSum2(arr, n, target-arr[i], ds, ans, i+1);
        ds.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<int> ds;
	vector<vector<int>> ans;
    int index=0;
    sort(arr.begin(), arr.end());
    findCombSum2(arr, n, target, ds, ans, index);
    return ans; 
}
