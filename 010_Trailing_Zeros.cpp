#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=5, ans=0;
    while(n/i > 0){
        ans += n/i;
        i*=5;
    }
    cout<<ans;
}
