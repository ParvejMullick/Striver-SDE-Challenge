#include <bits/stdc++.h> 

void solve(vector<vector<int> > &maze, int n, vector<vector<int> >& ans, vector<int>& vis,int di[], int dj[], int row, int col){
    if(row==n-1 && col==n-1){
        vis[n*n-1]=1;
        ans.push_back(vis);
        return;
    }
    
    for(int i=0;i<4;i++){
        int newx = row+di[i];
        int newy = col+dj[i];
        int mapIndex = n*row+col;//MAPPING 
        if(newx>=0 && newx<n && newy>=0 && newy<n && maze[row][col]==1 && vis[mapIndex]==0){
            vis[mapIndex]=1;
            solve(maze, n, ans, vis, di, dj, newx, newy);
            vis[mapIndex]=0;
        }
    }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int> > ans;
  vector<int> vis(n*n, 0);
  
  int di[]={1, 0, 0, -1};
  int dj[]={0, -1, 1, 0};
  int row=0;
  int col=0;
  
  if(maze[row][col]==1){
      solve(maze, n, ans, vis, di, dj, row, col);
  }
  return ans;
}
