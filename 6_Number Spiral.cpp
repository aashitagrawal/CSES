#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    vector<long long int> ans(n,0);
    for(long long int i=0; i<n; i++){
        long long int row, col;
        cin>>row>>col;
 
        long long int spiral_number = max(row, col);
        bool isIncreasing = spiral_number%2==1 ? true : false;
        long long int first_number = (spiral_number-1) * (spiral_number-1) + 1;
        long long int position = row==spiral_number ? col : spiral_number+spiral_number-row;
        ans[i] = isIncreasing ? first_number+position-1 : spiral_number*spiral_number - position + 1;
    }
    for(long long int num : ans) cout<< num <<'\n';
}
