#include<bits/stdc++.h>
using namespace std;
 
int N;
int dx[] = {1,-1,1,-1,2,-2,2,-2};
int dy[] = {2,2,-2,-2,1,1,-1,-1};
 
bool isValid(int x, int y){
    return (x>=0 && y>=0 && x<N && y<N);
}
 
int main(){
    cin>>N;
    vector<vector<int>> board (N,vector<int>(N,-1));
    queue<pair<int,int>> q;
    
    board[0][0]=0;
    q.push({0,0});
    while(!(q.empty())){
        auto [x,y] = q.front();
        q.pop();
 
        for(int i=0; i<=7; i++){
            if(isValid(x+dx[i], y+dy[i]) && board[x+dx[i]][y+dy[i]]==-1){
                board[x+dx[i]][y+dy[i]] = board[x][y]+1;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }
 
 
    for(auto ele:board){
        for(auto moves: ele) cout<<moves<<" ";
        cout<<'\n';
    }
}
