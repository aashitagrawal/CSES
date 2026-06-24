#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n,k;
    cin >> n >> k;
 
    ordered_set nums;
    for(int i=1; i<=n; i++)
        nums.insert(i);
 
    int position = 0;
    while(!nums.empty()){
        position = (position + k) % nums.size();
        auto iterator = nums.find_by_order(position);
        cout<<*iterator<<" ";
        nums.erase(iterator);
    }
}
