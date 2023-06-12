void solve(vector<int>& arr, int n, int k, vector<vector<int>>& ans, vector<int>& ds, int index){
  if(index==n){
    if(k==0){
    ans.push_back(ds);
    }
    return;
  }
  
  ds.push_back(arr[index]);
  solve(arr, n, k-arr[index], ans, ds, index+1);
  ds.pop_back();
  
  solve(arr, n, k, ans, ds, index+1);
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int index=0;
    solve(arr, n, k, ans, ds, index);
    return ans;
}
