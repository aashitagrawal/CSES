#include<bits/stdc++.h>
using namespace std;

void josephus(vector<int>& list){
    int N = list.size();

    if(N==0) return;
    if(N==1){
        cout<<list[0]<<" ";
        return;
    }

    for(int i=1; i<N; i+=2) //print all odd indices
        cout<<list[i]<<" ";
    
    vector<int> newList;
    if(N%2){
        newList.push_back(list[N-1]);
        for(int i=0; i<N-1; i+=2)
            newList.push_back(list[i]);
    }
    else{
        for(int i=0; i<N; i+=2)
            newList.push_back(list[i]);
    }
    
    josephus(newList);
}   

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++) vec[i]=i+1;

    josephus(vec);
}
