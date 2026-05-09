#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // Store obstacles in set
        set<pair<int,int>> st;
        for (auto &obs : obstacles) {
            st.insert({obs[0], obs[1]});
        }

        // Directions: North, East, South, West
        vector<pair<int,int>> dirs = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };

        int dir = 0; // initially North
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {

            if (cmd == -1) {
                // turn right
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {
                // turn left
                dir = (dir + 3) % 4;
            }
            else {
                // move forward step by step
                for (int i = 0; i < cmd; i++) {

                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;

                    // if obstacle found, stop moving
                    if (st.count({nx, ny})) {
                        break;
                    }

                    x = nx;
                    y = ny;

                    // update maximum distance
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};

int main() {
    Solution obj;

    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};

    int result = obj.robotSim(commands, obstacles);

    cout << "Maximum Distance Squared: " << result << endl;

    return 0;
}