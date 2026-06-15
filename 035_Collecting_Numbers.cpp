#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,temp;
    cin>>n;
 
    vector<int> indicies (n+1);
    for(int i=0; i<n; i++){
        cin>>temp;
        indicies[temp]=i;
    }
 
    int answer=1;
    for(int i=2; i<=n; i++){
        if(indicies[i-1] > indicies[i]){
            answer++;
        }
    }
    cout<<answer;
 
}
