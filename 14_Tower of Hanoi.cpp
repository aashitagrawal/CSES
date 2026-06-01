#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int,int>> moves;
 
void toh(int disks, int from, int to, int via){
    if(disks==1)
        moves.push_back({from,to});
    else{
        toh(disks-1, from, via, to);
        toh(1,from, to, via);
        toh(disks-1, via, to, from);
    }
}
 
int main(){
    int n;
    cin>>n;
    toh(n,1,3,2);
    cout<<moves.size()<<"\n";
    for(auto ele:moves) cout<<ele.first<<" "<<ele.second<<"\n";
}










#include<bits/stdc++.h>
using namespace std;
 
void toh(int disks, int from, int to, int via){
    if(disks==0)
        return;
    
    toh(disks-1, from, via, to);
    cout<<from<<" "<<to<<endl;
    toh(disks-1, via, to, from);
}
 
int main(){
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    toh(n,1,3,2);
}
