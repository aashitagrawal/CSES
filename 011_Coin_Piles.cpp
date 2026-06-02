#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if((a+b)%3==0){
            if(b>a){
            a = a ^ b;
            b = b ^ a;
            a = a ^ b;
            }
            if(a<= 2*b)
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
        else
            cout<<"NO"<<"\n";
    }
}
