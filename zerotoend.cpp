#include<iostream>
#include<vector>
using namespace std;

void moveZeroesToEnd(vector<int>&nums){
    int count=0;
    for(auto i=nums.begin();i!=nums.end();){
      if(*i==0){
        i=nums.erase(i);
        count++;
      }else ++i;
    }
    for(int k=0;k<count;k++){
        nums.push_back(0);
    }
}
int main(){
    vector<int>nums={0,1,2,0,3};
    moveZeroesToEnd(nums);
    for(int x:nums){
        cout<< x <<" ";
    }
    return 0;
}