#include<bits/stdc++.h>
using namespace std;
 
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
    int endMin = INT_MAX;
    for(int i=n-1; i>=0; i--){
        if(ranges[i].end >= endMin)
            parent[ranges[i].id] = 1;
        endMin = min(endMin, ranges[i].end);
    }
 
    vector<int> child(n,0);
    int endMax = 0;
    for(int i=0; i<n; i++){
        if(ranges[i].end <= endMax)
            child[ranges[i].id] = 1;
        endMax = max(endMax, ranges[i].end);
    }
 
    for(auto ele: parent)
        cout<<ele<<" ";
    cout<<'\n';
    for(auto ele: child)
        cout<<ele<<" ";    
}
