#include<bits/stdc++.h>
using namespace std;
 
bool sort_by_second(pair<int,int>&a, pair<int,int>&b){
    return a.second < b.second;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
 
    vector<pair<int,int>> movies (n);
    for(int i=0; i<n; i++) cin>>movies[i].first>>movies[i].second;
 
    sort(movies.begin(), movies.end(), sort_by_second);
 
    int answer=1;
    int curr_end_time = movies[0].second;
    for(int i=1; i<n; i++){
        if(movies[i].first >= curr_end_time){
            answer++;
            curr_end_time = movies[i].second;
        }
    }
    cout<<answer;
}
