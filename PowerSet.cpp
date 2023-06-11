#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    int n=v.size();
    for(int num=0;num<(1<<n);num++){
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(num & (1<<i)){
                temp.push_back(v[i]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
