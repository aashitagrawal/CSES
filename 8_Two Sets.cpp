#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if((n+2)%4==0 || (n+3)%4==0){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    vector<int> vec1;
    vector<int> vec2;
    
    if((n+1)%4==0){
        for(int i=0; i<=n; i+=4){
            vec1.push_back(i);
            vec1.push_back(i+3);
            vec2.push_back(i+1);
            vec2.push_back(i+2);
        }
        cout<<vec1.size()-1<<endl;
        for(int i=1; i<vec1.size(); i++)
            cout<<vec1[i]<<" ";
        cout<<endl;
 
        cout<<vec2.size()<<endl;
        for(int i=0; i<vec2.size(); i++)
            cout<<vec2[i]<<" ";
    }
    else{
        for(int i=1; i<=n; i+=4){
            vec1.push_back(i);
            vec1.push_back(i+3);
            vec2.push_back(i+1);
            vec2.push_back(i+2);
        }
        cout<<vec1.size()<<endl;
        for(int i=0; i<vec1.size(); i++)
            cout<<vec1[i]<<" ";
        cout<<endl;
 
        cout<<vec2.size()<<endl;
        for(int i=0; i<vec2.size(); i++)
            cout<<vec2[i]<<" ";
    }
}
