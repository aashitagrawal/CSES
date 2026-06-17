#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;

    multiset<int> towers;
    for(int i = 0; i<n; i++){
        int x = nums[i];
        auto p = towers.upper_bound(x);

        // 1. If pointer is at the end
        if(p == towers.end())
            towers.insert(x);
        // If the pointer is not 'x'
        else{
            towers.erase(p);
            towers.insert(x);
        }
    }
    cout<<towers.size();
    return 0;
}
