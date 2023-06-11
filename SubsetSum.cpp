#include <bits/stdc++.h> 

void findsubsetSum(vector<int> &num, int index, int sum, vector<int>& ans){
    if(index==num.size()){
        ans.push_back(sum);
        return;
    }
    
     
     findsubsetSum(num, index+1, sum+num[index], ans);
     
     findsubsetSum(num, index+1, sum, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    int index=0;
    int sum=0;
    vector<int> ans;
    findsubsetSum(num, index, sum, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
