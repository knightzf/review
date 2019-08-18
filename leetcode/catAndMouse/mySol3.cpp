#include "header.h"

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int DRAW = 0, MOUSE = 1, CAT = 2;
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(3, 0)));
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(3, 0)));

        for(int mouse = 0; mouse < n; ++mouse) {
            for(int cat = 0; cat < n; ++cat) {
                degree[mouse][cat][MOUSE] = graph[mouse].size();
                degree[mouse][cat][CAT] = graph[cat].size();
                if(find(graph[cat].begin(), graph[cat].end(), 0) != graph[cat].end())
                    --degree[mouse][cat][CAT];
            }
        }

        queue<vector<int>> q;
        for(int i = 1; i < n; ++i) {
            color[0][i][MOUSE] = MOUSE;
            color[0][i][CAT] = MOUSE;
            color[i][i][MOUSE] = CAT;
            color[i][i][CAT] = CAT;
            q.push({0, i, MOUSE});
            q.push({0, i, CAT});
            q.push({i, i, MOUSE});
            q.push({i, i, CAT});
        }

        auto getParent = [&](int mouse, int cat, int turn) {
            vector<vector<int>> res;
            if(turn == MOUSE) {
                for(int i : graph[cat]) {
                    if(i > 0) res.push_back({mouse, i, 3 - turn});
                }
            } else {
                for(int i : graph[mouse]) {
                    res.push_back({i, cat, 3 - turn});
                }
            }
            return res;
        };

        while(!q.empty()) {
            const auto& s = q.front();
            int mouse = s[0], cat = s[1], turn = s[2], col = color[mouse][cat][turn];
            for(const auto& p : getParent(mouse, cat, turn)) {
                int preMouse = p[0], preCat = p[1], preTurn = p[2];
                int& preColor = color[preMouse][preCat][preTurn];
                if(preColor == DRAW) {
                    if(preTurn == col) {
                        preColor = col;
                        q.push({preMouse, preCat, preTurn});
                    }
                    else {
                        if(--degree[preMouse][preCat][preTurn] == 0) {
                            preColor = 3 - preTurn;
                            q.push({preMouse, preCat, preTurn});
                        }
                    }
                }
            }
            q.pop();
        }

        return color[1][2][MOUSE];
    }
};

int main()
{
    Solution s;
}