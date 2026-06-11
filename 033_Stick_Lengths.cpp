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
 
    int median = vec[n/2];
    long long answer=0;
    for(auto ele:vec)
        answer+=abs(median-ele);
    
    cout<<answer;
}
