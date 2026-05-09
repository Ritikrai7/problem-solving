#include<bits\stdc++.h>
using namespace std;

int findMinimumIndex(vector<int>&input){
    int lo=1,high=input.size()-1;
    int ans=-1;
    while (lo<=high){
        int mid=lo+(high-lo)/2;
        if(input[mid]>input[mid-1]){
            ans=mid;
            lo=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}