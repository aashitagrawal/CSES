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

    map<int, int> freq;
    int left = 0;
    int answer = INT_MIN;

    for(int right = 0; right<n; right++){
        freq[nums[right]]++;

        // sihft the window to left until the window has unique elements
        while(freq[nums[right]]==2){
            freq[nums[left]]--;
            left++;
        }

        answer = max(answer, right-left+1);
    }

    cout<<answer;
    return 0;
}
