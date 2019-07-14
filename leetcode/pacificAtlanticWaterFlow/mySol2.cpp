#include "header.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        function<void(int, int, int)> dfs = [&](int i, int j, int tag) {
            if(visited[i][j] == 3) return;
            if(tag == 3) visited[i][j] = 3;
            else if(visited[i][j] != tag) visited[i][j] += tag;
            static vector<int> diff{-1, 0, 1, 0, -1};
            for(int k = 0; k < 4; ++k) {
                int x = i + diff[k], y = j + diff[k + 1];
                if(x >= 0 && x < m && y >= 0 && y < n && visited[x][y] != 3 && visited[x][y] != tag
                    && matrix[x][y] >= matrix[i][j])
                    dfs(x, y, tag);
            }
        };
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int tag = 0;
                if(i == 0 || j == 0) tag += 1;
                if(i == m - 1 || j == n - 1) tag += 2;
                if(tag != 0) dfs(i, j , tag);
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visited[i][j] == 3) res.emplace_back(vector<int>{i, j});
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}