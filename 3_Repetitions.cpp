#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    long int n = s.size(), local=1, global=1;
    for(long int i =1; i<n; i++){
        if(s[i]==s[i-1]) local++;
        else{
            global = max(local,global);
            local=1;
        }
    }
    cout<<max(local,global);
}
