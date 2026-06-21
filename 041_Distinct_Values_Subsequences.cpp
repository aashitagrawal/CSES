#include<bits/stdc++.h>
using namespace std;

int main(){
    int M = 1e9+7;
    int n;
    cin>>n;
    vector<int> vec (n);
    map<int,int> myMap;
    for(int i=0; i<n; i++){
        cin>>vec[i];
        myMap[vec[i]]++;
    }
    
    long long total_count=1;
    for(const auto& ele:myMap)
        total_count = (total_count%M * (ele.second+1)%M)%M;
    cout<<(total_count-1+M)%M;
}
