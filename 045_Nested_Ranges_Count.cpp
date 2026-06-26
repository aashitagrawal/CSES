#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update> ordered_multiset;
 
 
struct Range {
    int id, start, end;
};
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
    vector<Range> ranges (n);
 
    for(int i=0; i<n; i++){
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].id=i;
    }
 
    // start ASC, end DESC
    sort(
        ranges.begin(),
        ranges.end(),
        [](const Range& a, const Range &b){
            if (a.start != b.start) // sort 'start' ASC
                return a.start < b.start;
            return a.end > b.end; // fallback: sort 'end' DESC
        }
    );
 
    vector<int> parent(n,0);
    ordered_multiset helper;
    for(int i=n-1; i>=0; i--){
        parent[ranges[i].id] = helper.order_of_key(ranges[i].end + 1); // count of elements <= ranges[i].end
        helper.insert(ranges[i].end);
    }
 
    helper.clear();
    vector<int> child(n,0);
    for(int i=0; i<n; i++){
        child[ranges[i].id] = helper.size() - helper.order_of_key(ranges[i].end); // count of elements >= ranges[i].end
        helper.insert(ranges[i].end);
    }
 
    for(auto ele: parent)
        cout<<ele<<" ";
    cout<<'\n';
    for(auto ele: child)
        cout<<ele<<" ";
}
