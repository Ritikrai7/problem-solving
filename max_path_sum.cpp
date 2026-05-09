#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;

int f(int i, int j){
    // Boundary condition
    if(j < 0 || j >= m) return INT_MIN;

    // Base case
    if(i == 0) return a[0][j];

    int s  = a[i][j] + f(i-1, j);     // up
    int ld = a[i][j] + f(i-1, j-1);   // left diagonal
    int rd = a[i][j] + f(i-1, j+1);   // right diagonal

    return max(s, max(ld, rd));
}

int main(){
    cin >> n >> m;

    a.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int maxi = INT_MIN;

    // Try all columns in last row
    for(int j = 0; j < m; j++){
        maxi = max(maxi, f(n-1, j));
    }

    cout << maxi << endl;

    return 0;
}