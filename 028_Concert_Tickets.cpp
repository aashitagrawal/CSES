#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int num_ticket, num_cust;
    cin>>num_ticket>>num_cust;
    
    multiset<int> ticket_prices;
    vector<int> cust_max_price(num_cust, 0);
    for(int i=0; i<num_ticket; i++){
        int price;
        cin>>price;
        ticket_prices.insert(price);
    }
    for(int i=0; i<num_cust; i++) cin>>cust_max_price[i];
    
 
    for(int i=0; i<num_cust; i++){
        auto p = ticket_prices.upper_bound(cust_max_price[i]);
        
        if(p==ticket_prices.begin()){
            cout<<-1<<'\n';
            continue;
        }
        p--;
        cout<<*p<<'\n';
        ticket_prices.erase(p);
    }
 
}
