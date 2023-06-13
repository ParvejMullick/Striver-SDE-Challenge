#include <bits/stdc++.h>

long long merge(long long *arr, long long low, long long mid, long long high){
    long long left=low;
    long long right=mid+1;
    
    vector<long long> temp;
    long long count=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            count += (mid - left +1);
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return count;
}

long long mergeSort(long long *arr, long long low, long long high){
    long long count=0;
    if(low>=high){
        return count;
    }
    
    long long mid = (low+high)/2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    count += merge(arr, low, mid, high);
    return count;
}

long long getInversions(long long *arr, int n){
    long long low=0;
    long long high=n-1;
    return mergeSort(arr, low, high);
}
