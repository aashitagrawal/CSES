#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    
    vector<int> vec (n);
    for(int i=0; i<n; i++) cin>>vec[i];
 
    long long curr_sum=0;
    long long max_sum=LLONG_MIN;
    for(long long ele:vec){
        curr_sum = max(ele, curr_sum+ele);
        max_sum = max(curr_sum, max_sum);
    }
    cout<<max_sum;
}
