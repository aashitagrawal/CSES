#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int n = s.size(), index=0, oddCount=0;
    char oddChar = '\0';
    map<char, int>m;
    for(char c:s) m[c]++;
 
    for(auto &ele:m){
        if(ele.second%2==1){
            oddCount++;
            oddChar = ele.first;
        }
    }
 
    if(oddCount>1){
        cout<<"NO SOLUTION";
        return 0;
    }
    for(auto &ele:m){
        if(ele.first == oddChar) continue;
        int num = ele.second/2;
        while(num--){
            s[index] = ele.first;
            s[n-1-index] = ele.first;
            index++;
        }
    }
    for(int i=index; i<=(n-index-1); i++)
        s[i] = oddChar;
    cout<<s;
}
