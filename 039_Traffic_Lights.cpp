#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int x,n;
    cin >>x>> n;
 
    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;
    
    multiset<int> lengths;
    lengths.insert(x);
 
    set<int> light_position;
    light_position.insert(0);
    light_position.insert(x);
 
    for(int i=0; i<n; i++){
        int curr = nums[i];
        
        auto p = light_position.lower_bound(curr);
        int right = *p;
        int left = *prev(p);
 
        light_position.insert(curr);
 
        lengths.erase(lengths.find(right-left));
        lengths.insert(curr-left);
        lengths.insert(right-curr);
 
        cout<<*lengths.rbegin()<<" ";
    }
}
