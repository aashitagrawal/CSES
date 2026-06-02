#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    long long int ans=0;
    cin>>n;
    vector<long int> vec;
    for(int i=0; i<n; i++){
        long int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    for(int i=1; i<n; i++){
        if(vec[i]<vec[i-1]){
            ans+=vec[i-1]-vec[i];
            vec[i]=vec[i-1];
        }
    }
    cout<<ans;
}
