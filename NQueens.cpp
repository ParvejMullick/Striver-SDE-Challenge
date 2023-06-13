void solve(int n, vector<int>& board, vector<vector<int>>& ans, vector<int>& lrow, vector<int>& udia, vector<int>& ldia, int col){
    if(col==n){
        ans.push_back(board);
        return;
    }
    
    for(int row=0;row<n;row++){
        int mapIndex=n*col+row; /* MAPPING 2-D ARRAY TO A 1-D "COLUMN WISE": 
        Formula -> (Total no. of rows)*(current column index)+(current row index) = Index of 1-D ARRAY of size (row*col)
        
        ***EXTRA***
        MAPPING 2-D ARRAY TO A 1-D "ROW WISE"(Mostly used): 
        Formula -> (Total no. of columns)*(current row index)+(current column index) = Index of 1-D ARRAY of size (row*col)
        */
        if(board[mapIndex]==0 && lrow[row]==0 && udia[n-1+ col - row]==0 && ldia[row+col]==0 ){
            board[mapIndex]=1;
            lrow[row]=1;
            ldia[row+col]=1;
            udia[n-1+ col - row]=1;
            solve(n, board, ans, lrow, udia, ldia, col+1);
            board[mapIndex]=0;
            lrow[row]=0;
            ldia[row+col]=0;
            udia[n-1+ col - row]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> board(n*n , 0);
    vector<vector<int>> ans;
    
    vector<int> lrow(n, 0), udia(2*n - 1, 0), ldia(2*n - 1, 0);
    int col=0;
    solve(n, board, ans, lrow, udia, ldia, col);
    return ans;
}
