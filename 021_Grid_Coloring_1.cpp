#include<bits/stdc++.h>
using namespace std;

char calculate(const vector<vector<char>>&grid, int row, int col){
    array<bool,128> visited{}; //intizaled to false
    
    visited[grid[row][col]] = true;
    if(row-1>=0) visited[grid[row-1][col]] = true;
    if(col-1>=0) visited[grid[row][col-1]] = true;

    for(auto ele:{'A','B','C','D'})
        if(!visited[ele])
            return ele;

    return 'A'; //fallback, but code will never reach here
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m,'\0'));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            grid[i][j] = calculate(grid,i,j);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<grid[i][j];
        cout<<'\n';
    }
}
