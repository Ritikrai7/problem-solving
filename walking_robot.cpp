#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for (auto &obs : obstacles) {
            st.insert({obs[0], obs[1]});
        }
        vector<pair<int,int>> dirs = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        int dir=0;
        int x,y=0;
        int maxDist=0
        for (int cmd : commands) {

            if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                for (int i = 0; i < cmd; i++) {

                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;
                    if (st.count({nx, ny})) {
                        break;
                    }

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};