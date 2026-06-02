#include<bits/stdc++.h>
using namespace std;
 
set<string> ans;
 
void string_perm(const string &s, string &auxilliary_string, vector<bool> &flags){
    if(auxilliary_string.size() == s.size()){
        ans.insert(auxilliary_string);
        return;
    }
 
    for(int i = 0; i < s.size(); i++){
        if(flags[i]) continue;
 
        auxilliary_string.push_back(s[i]);
        flags[i] = true;
        
        string_perm(s, auxilliary_string, flags);
        
        auxilliary_string.pop_back();
        flags[i] = false;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    if (!(cin>>s)) return 0;
    
    sort(s.begin(), s.end());
 
    string auxilliary_string = "";
    vector<bool> flags(s.size(), false);
 
    string_perm(s, auxilliary_string, flags);
 
    cout <<ans.size()<<"\n";
    for(auto &ele:ans) cout<<ele<<"\n";
}
