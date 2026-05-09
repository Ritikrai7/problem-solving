#include<bits/stdc++.h>
using namespace std;
int f(int ind,int w,vector<int>&wt,vector<int>&val,
      vector<vector<int>>&dp){
    if(ind==0){     // base class for 01 knapsack...
        if(wt[0] <= w) return val[0];
        else return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];//here we have created a dp
    // array for memoization...
    int notTake = f(ind-1,w,wt,val,dp);
    int take = INT_MIN;
    if(wt[ind] <= w){
        take = val[ind] + f(ind-1,w-wt[ind],wt,val,dp);
    }
    return dp[ind][w] = max(take,notTake);
}
int knapsack01(vector<int>&wt, vector<int>&val, int n, int maxWeight){
    vector<vector<int>> dp(n, vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,wt,val,dp);
}
 int main(){
    int n;
    cout << "Enter number of items: ";// taking input of number of items
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter weights:\n";
    for(int i=0;i<n;i++){
        cin >> wt[i];
    }
    cout << "Enter values:\n";// taking input of values...
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    int maxWeight;
    cout << "Enter maximum capacity of knapsack: ";
    cin >> maxWeight;
    int ans = knapsack01(wt,val,n,maxWeight);
    cout << "Maximum value = " << ans << endl;
    return 0;
}