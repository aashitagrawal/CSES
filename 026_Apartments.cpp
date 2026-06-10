#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int desired_area[n];
    int actual_area[m];
    for(int i=0; i<n; i++) cin>>desired_area[i];
    for(int i=0; i<m; i++) cin>>actual_area[i];
 
    sort(desired_area, desired_area+n);
    sort(actual_area, actual_area+m);
 
    int house=0,people=0, answer=0;
    while(people<n && house<m){
        if(desired_area[people]+k <actual_area[house]) people++;
        else if(desired_area[people]-k > actual_area[house]) house++;
        else {people++; house++; answer++;}
    }
    cout<<answer;
}
