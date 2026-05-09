#include<iostream>
#include<vector>
using namespace std;
int firstOccurence(vector<int>&v,int target){
    int n=v.size();
    int low=0;
    int ans=-1;
    int high=v.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(v[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(v[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>v={2,4,5,5,7,7,10,13,16,19};
    int target=7;
    cout<<firstOccurence(v,target)<<endl;
}