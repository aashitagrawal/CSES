#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin>>q;
    while(q--){
        long long position;
        cin>>position;
        position--;

        long long quantity = 9;
        long long digits = 1;
        long long start_num = 1;
        
        while(position>= digits*quantity){
            position-=(digits*quantity);
            digits++;
            quantity*=10;
            start_num*=10;
        }
        
        long long actual_number = start_num + position/digits;
        long long index = position%digits;
        cout<<to_string(actual_number)[index]<<'\n';
    }
}
