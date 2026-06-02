#include<bits/stdc++.h>
using namespace std;
 
long long apple_division(const vector<int>&vec, int index, long long current_sum, const long long &total_sum){
    if(index == vec.size())
        return abs(total_sum-current_sum-current_sum);
 
    long long exclude_current_apple = apple_division(vec, index+1, current_sum, total_sum);
    long long include_current_apple = apple_division(vec, index+1, current_sum+vec[index], total_sum);
    return min(exclude_current_apple, include_current_apple);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    short int n;
    cin>>n;
 
    vector<int> vec(n,1);
    long long total_sum=0;
 
    for(int i=0; i<n; i++){
        cin>>vec[i];
        total_sum+=vec[i];
    }
 
    cout<<apple_division(vec, 0, 0LL, total_sum);
}
