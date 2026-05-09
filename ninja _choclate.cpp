
#include<bits\stdc++.h>
using namespace std;

int f(int i,int j1,int j2,int r,int c,vector<vector<int>>&grid,
vector<vector<vector<int>>>&dp){

    if(j1<0 || j2<0 || j1>=c || j2>=c){
        return INT16_MIN;
    }
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int maxi=INT16_MIN;

    for(int dj1=-1; dj1<=+1; dj1++){  // here e are using 2 for loop for checki
        for(int dj2=-1;dj2<=+1;dj2++){
            int value=0;
            if(j1==j2) value=grid[i][j1];
            else value=grid[i][j1]+grid[i][j2];
            value+=f(i+1,j1+dj1,j2+dj2,c,grid,dp);  
        }
    }
    return maxi=dp[i][j1][j2];
}