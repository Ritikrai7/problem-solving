#include<bits/stdc++.h>
using namespace std;

// your functions here
int f(int ind, vector<int>& nums, vector<int>& dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + f(ind-2, nums, dp);
    int not_pick = f(ind-1, nums, dp);

    return dp[ind] = max(pick, not_pick);
}

int rob(vector<int>& nums){
    int n = nums.size();

    if(n==1) return nums[0];

    vector<int>temp1,temp2;

    for(int i = 1; i < n; i++) temp1.push_back(nums[i]);
    for(int i = 0; i < n-1; i++) temp2.push_back(nums[i]);

    vector<int> dp1(n-1, -1), dp2(n-1, -1);

    int ans1 = f(n-2, temp1, dp1);
    int ans2 = f(n-2, temp2, dp2);

    return max(ans1, ans2);
}

int main(){
    vector<int>nums={2,3,2,9};
    cout << rob(nums);
}