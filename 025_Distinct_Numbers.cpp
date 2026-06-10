#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,temp;
    cin>>n;
 
    set<int> mySet;
    for(int i=0; i<n; i++){
        cin>>temp;
        mySet.insert(temp);
    }
    cout<<mySet.size();
 
}
