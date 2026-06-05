#include<bits/stdc++.h>
using namespace std;
const int N = 7;
int answer = 0;

void dfs(const string& path, bool visited[][N], int x, int y, int steps){
    // Reached perfectly at 48 steps
    if(x==6 && y==0 && steps==48){ answer++; return; }

    // 1. Reached early
    if(x==6 && y==0 && steps<48) return;

    // 2. Already visited (out of bounds is already checked before calling)
    if(visited[x][y]) return;

    // 3. Reached somewhere else at step 48
    if(steps==48) return;

    // 4. If the path is trapped - horizontally or vertically
    if((x+1>=N || visited[x+1][y]) && (x-1<0 || visited[x-1][y]) && !(y+1>=N || visited[x][y+1]) && !(y-1<0 || visited[x][y-1])) return;
    if((y+1>=N || visited[x][y+1]) && (y-1<0 || visited[x][y-1]) && !(x+1>=N || visited[x+1][y]) && !(x-1<0 || visited[x-1][y])) return;

    visited[x][y]=true;
    if(path[steps]=='?' || path[steps]=='D') if(x+1<N && !visited[x+1][y]) dfs(path,visited,x+1,y,steps+1);
    if(path[steps]=='?' || path[steps]=='U') if(x-1>=0 && !visited[x-1][y]) dfs(path,visited,x-1,y,steps+1);
    if(path[steps]=='?' || path[steps]=='R') if(y+1<N && !visited[x][y+1]) dfs(path,visited,x,y+1,steps+1);
    if(path[steps]=='?' || path[steps]=='L') if(y-1>=0 && !visited[x][y-1]) dfs(path,visited,x,y-1,steps+1);
    visited[x][y]=false;
}

int main(){
    string path;
    cin >> path;
    bool visited[N][N] = {};
    dfs(path, visited, 0, 0, 0);
    cout << answer;
}
