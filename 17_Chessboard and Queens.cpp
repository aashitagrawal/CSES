#include<bits/stdc++.h>
using namespace std;
 
const int N = 8;
int answer = 0;
 
 
void NQueens(const vector<vector<char>> &board, int row, bool queens_col[], bool queens_diag1[], bool queens_diag2[]){
    if(row==N){
        answer++;
        return;
    }
 
    for(int col=0; col<N; col++){
        if(board[row][col]=='*' || queens_col[col] || queens_diag1[row-col+N-1] || queens_diag2[row+col]) continue;
 
        queens_col[col] = queens_diag1[row-col+N-1] = queens_diag2[row+col] = true;
        NQueens(board, row+1, queens_col, queens_diag1, queens_diag2);
        queens_col[col] = queens_diag1[row-col+N-1] = queens_diag2[row+col] = false;
    }
}
 
void NQueens(const vector<vector<char>> &board, int row, int queens_col, int queens_diag1, int queens_diag2){
    if(row==N){
        answer++;
        return;
    }
 
    for(int col=0; col<N; col++){
        if(board[row][col]=='*' || (queens_col>>col)&1 || (queens_diag1>>(row-col+N-1))&1 || (queens_diag2>>(row+col))&1) continue;
        NQueens(board,
                row+1,
                queens_col | 1<<col,
                queens_diag1 | 1<<(row-col+N-1),
                queens_diag2 | 1<<(row+col));
    }
}
 
 
int main(){
    vector<vector<char>> board (N, vector<char>(N, '.'));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>board[i][j];
 
    bool queens_col[N];
    bool queens_diag1[2*N -1];
    bool queens_diag2[2*N -1];
 
    fill_n(queens_col, N, false);
    fill_n(queens_diag1, 2*N-1, false);
    fill_n(queens_diag2, 2*N-1, false);
 
    // NQueens(board,0,queens_col, queens_diag1, queens_diag2);
    NQueens(board,0,0,0,0);
    cout<<answer;
}
