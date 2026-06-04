#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    const int N=s.size();

    int myMap[128] = {0};
    for(auto c:s) myMap[(int)c]++;

    auto isValid = [&](int remaining_characters){
        for(int i='A'; i<='Z'; ++i)
            if((2*myMap[i]) > (remaining_characters+1))
                return false;
        return true;
    };

    if(!isValid(N)){
        cout<<-1;
        return 0;
    }

    char prev = '*';
    for(int j=1; j<=N; j++){
        for(char i='A'; i<='Z'; ++i){
            if(i==prev) continue;
            if(!myMap[(int)i]) continue;

            myMap[i]--;
            if(isValid(N-j)){
                cout<<i;
                prev=i;
                break;
            }
            myMap[i]++;
        }
    }
}
