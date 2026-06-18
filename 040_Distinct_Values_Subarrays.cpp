#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<int> nums(n);
    for (int& num : nums)
        cin >> num;
    
    map<int,int> freq;
    long long answer, left;
    answer = left  = 0;
 
    for(int right=0; right<n; right++){
        freq[nums[right]]++;
 
        while(freq[nums[right]]==2){
            freq[nums[left]]--;
            left++;
        }
 
        answer += (right - left + 1);
    }
    cout<<answer;
}
