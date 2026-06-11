#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,sum;
    cin>>n>>sum;
 
    vector<pair<int,int>> vec (n);
    for(int i=0; i<n; i++){
        cin>>vec[i].first;
        vec[i].second = i+1;
    }
 
    sort(vec.begin(), vec.end());
 
    int left=0, right=n-1;
    while(left<right){
        if(vec[left].first+vec[right].first == sum) break;
        if(vec[left].first+vec[right].first > sum) right--;
        else left++;
    }
    if(left==right) cout<<"IMPOSSIBLE";
    else cout<<vec[left].second<<" "<<vec[right].second;
}
