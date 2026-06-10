#include<bits/stdc++.h>
using namespace std;

int main(){
    int num_child, max_weight;
    cin>>num_child>>max_weight;

    int child_weight[num_child];
    for(int i=0; i<num_child; i++) cin>>child_weight[i];

    sort(child_weight, child_weight+num_child, greater<int>());

    int left=0, right=num_child-1, answer=0;
    while(left<=right){
        answer++;

        if(left!=right && child_weight[left]+child_weight[right]<=max_weight)
            {left++; right--;}
        else
            left++;
    }
    cout<<answer;

}
