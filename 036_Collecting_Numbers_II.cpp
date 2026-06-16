#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m;
    cin>>n>>m;
 
    vector<int> values(n + 1);
    vector<int> indicies(n + 1); 
 
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        indicies[values[i]] = i;
    }
 
    int answer=1;
    for(int i=2; i<=n; i++){
        if(indicies[i-1] > indicies[i]){
            answer++;
        }
    }
 
    while(m--){
        int a,b;
        cin>>a>>b;
 
        if(a==b){
            cout<<answer<<'\n';
            continue;
        }
 
        int x = values[a];
        int y = values[b];
 
        if(x>y)
            swap(x,y);
 
        //Subtract old penalties
        if(x>1)
            if(indicies[x] < indicies[x-1])
                answer--;
        
        if(x<n)
            if(indicies[x+1] < indicies[x])
                answer--;
 
        if(y>1 &&  y-1 != x) //If x and y are consecutive
            if(indicies[y] < indicies[y-1])
                answer--;
 
        if(y<n)
            if(indicies[y+1] < indicies[y])
                answer--;
 
        
        //Perform Swap
        swap(values[a], values[b]);
        swap(indicies[x], indicies[y]);
 
        //Add the new penalties
        if(x>1)
            if(indicies[x] < indicies[x-1])
                answer++;
        
        if(x<n)
            if(indicies[x+1] < indicies[x])
                answer++;
 
        if(y>1 &&  y-1 != x) //If x and y are consecutive
            if(indicies[y] < indicies[y-1])
                answer++;
 
        if(y<n)
            if(indicies[y+1] < indicies[y])
                answer++;
 
        cout<<answer<<'\n';
    }
 
}
