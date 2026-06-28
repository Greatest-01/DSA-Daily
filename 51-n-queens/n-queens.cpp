class Solution {
public:
    void solution(int col,int n,vector<string>& board,vector<vector<string>> &ans,vector<int>&left_row,vector<int>&upper_dig,vector<int>&lower_dig){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for (int row=0;row<n;row++){
            if(left_row[row]==0 && upper_dig[row+col]==0 && lower_dig[n-1+col-row]==0){
                board[row][col]='Q';
                left_row[row]=1;
                upper_dig[row+col]=1;
                lower_dig[n-1+col-row]=1;
                solution(col+1,n,board,ans, left_row,upper_dig,lower_dig);
                board[row][col]='.';
                left_row[row]=0;
                upper_dig[row+col]=0;
                lower_dig[n-1+col-row]=0;
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       string s(n,'.');
       for ( int i=0;i<n;i++){
        board[i]=s;
       }
       vector<int>left_row(n,0),upper_dig(2*n-1,0),lower_dig(2*n-1,0);
       solution(0,n,board,ans ,left_row,upper_dig,lower_dig);
       return ans ;
    }
};