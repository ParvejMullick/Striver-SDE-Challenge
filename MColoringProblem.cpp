#include <bits/stdc++.h> 

bool isValid(int n, vector<vector<int>> &mat, int color[], int node, int col){
    for(int i=0;i<n;i++){
        if( i != node && mat[i][node]==1 && color[i]==col){
            return false;
        }
    }
    return true;
}

bool solve(int n, vector<vector<int>> &mat, int m, int color[], int node){
    if(node==n){
        return true;
    }
    
    for(int col=1;col<=m;col++){
        if(isValid(n, mat, color, node, col)==true){
            color[node] = col;
            if(solve(n, mat, m,color, node+1)==true){
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    int color[n] = {0};
    int node=0;
    if(solve(n, mat, m,color, node)==true){
    return "YES";
    }
    return "NO";
}
