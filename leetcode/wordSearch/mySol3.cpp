#include "header.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		static vector<int> diff{-1, 0, 1, 0, -1};
		
		function<bool(int, int, int)> dfs = [&](int i, int j, int idx)
		{
			if(idx == len - 1) return true;

			visited[i][j] = true;
			for(int k = 0; k < 4; ++k)
			{
				int x = i + diff[k], y = j + diff[k + 1];
				if(x >= 0 && x < m && y >=0 && y < n && !visited[x][y] && 
                  board[x][y] == word[idx + 1]) {
					if(dfs(x, y, idx + 1)) return true;
				}
			}
			visited[i][j] = false;
			return false;
		};

		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(board[i][j] == word[0] && dfs(i, j, 0)) return true;
			}
		}
		return false;
    }
};


int main()
{
    Solution s;
}