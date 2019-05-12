#include "header.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<pair<int, int>> v;

        auto valid = [&](const vector<pair<int, int>>& v, int i, int j)
        {
            for(const auto& p : v)
            {
                if(p.first == i || p.second == j || 
                   (abs(p.first - i) == abs(p.second - j))) return false;
            }
            return true;
        };

        function<void(int)> dfs = [&](int i)
        {
            if(i == n) {
                vector<string> board(n, string(n, '.'));
                for(const auto& p : v) {
                    board[p.first][p.second] = 'Q';
                }
                res.emplace_back(board);
                return;
            }

            for(int j = 0; j < n; ++j)
            {
                if(valid(v, i, j)) {
                    v.emplace_back(make_pair(i, j));
                    dfs(i + 1);
                    v.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};

int main()
{
    Solution s;
}