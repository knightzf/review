#include "header.h"

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(2 * n, vector<vector<int>>(n, vector<int>(n, -1)));
        function<int(int, int, int)> f = [&](int t, int mouse, int cat) {
            //cout<<t<<" "<<mouse<<" "<<cat<<endl;
            if(t == 2 * n) return 0;
            if(mouse == 0) return 1;
            if(mouse == cat) return 2;
            if(dp[t][mouse][cat] != -1) return dp[t][mouse][cat];
			bool flag = true;
            if(t & 1) { // cat
                for(int i : graph[cat]) {
                    if(i != 0) {
                        int r = f(t + 1, mouse, i);
                        if(r == 2) return dp[t][mouse][cat] = 2;
                        else if(r != 1) flag = false;
                    }
                }
				if(flag) return dp[t][mouse][cat] = 1;
				else return dp[t][mouse][cat] = 0;
            } else { // mouse
                for(int i : graph[mouse]) {
                    int r = f(t + 1, i, cat);
                    if(r == 1) return dp[t][mouse][cat] = 1;
                    else if(r != 2) flag = false;
                }
                if(flag) return dp[t][mouse][cat] = 2;
				else return dp[t][mouse][cat] = 0;
            }
        };

        return f(0, 1, 2);
    }
};

int main()
{
    Solution s;
}