#include<bits/stdc++.h>
using namespace std;
 
long long binary_exponentiation_iterative(long long base, long long exp, long long modulo) {
    if (modulo == 1) return 0; 
    
    base = (base % modulo + modulo) % modulo; 
    long long answer = 1;
 
    while (exp > 0) {
        if (exp & 1)
            answer = (answer * base) % modulo;        
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return answer;
}
 
int main(){
    long long n;
    cin>>n;
    cout<<binary_exponentiation_iterative(2,n,1e9+7);
}
