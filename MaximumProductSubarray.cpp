#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int prefixProd = 1;
    int suffixProd = 1;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        prefixProd = prefixProd*arr[i];
        suffixProd = suffixProd*arr[n-i-1];
        
        maxi = max(maxi, max(prefixProd, suffixProd));
        if(prefixProd==0){
            prefixProd = 1;
        }
        if(suffixProd==0){
            suffixProd = 1;
        }
    }
    return maxi;
}
