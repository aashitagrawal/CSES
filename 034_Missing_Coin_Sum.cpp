#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<int> vec (n);
    for(int i=0; i<n; i++) cin>>vec[i];
    sort(vec.begin(), vec.end());

    long long prefix_sum=1;
    for(auto ele:vec){
        if(ele<=prefix_sum) prefix_sum+=ele;
        else break;
    }
    cout<<prefix_sum;
}
