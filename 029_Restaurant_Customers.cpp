#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    
    vector<pair<int,int>> time;
    for(int i=0; i<n; i++){
        int arrival,leaving;
        cin>>arrival>>leaving;
        time.push_back({arrival,1});
        time.push_back({leaving,-1});
    }
    
    sort(time.begin(), time.end());
 
    int current_number_of_people = 0;
    int max_people = -1;
    for(int i=0; i<2*n; i++){
        if(time[i].second==1)
            current_number_of_people++;
        else
            current_number_of_people--;
        max_people = max(max_people, current_number_of_people);
    }
    cout<<max_people;
}
