#include<bits/stdc++.h>
using namespace std;

vector<int>top_k_frequent_elements(vector<int>&nums,int k){
    sort(nums.begin(),nums.end());
    vector<pair<int,int>>freq;
    int count=1;
   for(int i=1;i<nums.size();i++){
    if(nums[i]==nums[i-1]){
        count++;
    }
    else{
        freq.push_back({count,nums[i-1]});
        count=1;
    }
 }
 freq.push_back({count,nums[nums.size()-1]});
 sort(freq.begin(),freq.end(),greater<pair<int,int>>());
    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(freq[i].second);
    }
    return ans;
}
int main(){
    vector<int>nums={1,1,1,2,2,3};
    int k=2;
    vector<int>ans=top_k_frequent_elements(nums,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}