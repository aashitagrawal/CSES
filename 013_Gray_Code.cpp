#include<bits/stdc++.h>
using namespace std;
int main(){
    short int n;
    cin>>n;
    int max = pow(2,n)-1;
    for(int i=0; i<=max; i++)
        cout<<bitset<16>(i ^ (i>>1)).to_string().substr(16-n)<<'\n';
}
