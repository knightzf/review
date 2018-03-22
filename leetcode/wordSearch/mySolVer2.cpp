#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

   class Solution {
    public:
    	 bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()){
            return false;
        }
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

bool dfs(vector<vector<char>>& board, const string& word, int pos, int r, int c){
        if(pos == word.length() - 1){
            return true;
        }
        char cur = board[r][c];
        board[r][c] = '.';
        if(r + 1 < board.size() && board[r + 1][c] == word[pos + 1] && dfs(board, word, pos + 1, r + 1, c)){
            return true;
        }
        if(r >= 1 && board[r - 1][c] == word[pos + 1] && dfs(board, word, pos + 1, r - 1, c)){
            return true;
        }
        if(c + 1 < board[0].size() && board[r][c + 1] == word[pos + 1] && dfs(board, word, pos + 1, r, c + 1)){
            return true;
        }
        if(c >= 1 && board[r][c - 1] == word[pos + 1] && dfs(board, word, pos + 1, r, c - 1)){
            return true;
        }
        board[r][c] = cur;
        return false;
    }
    };

int main() {
    Solution s;
    //vector<vector<char>> a{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> a{
        {'F','Y','C','E','N','R','D'},
        {'K','L','N','F','I','N','U'},
        {'A','A','A','R','A','H','R'},
        {'N','D','K','L','P','N','E'},
        {'A','L','A','N','S','A','P'},
        {'O','O','G','O','T','P','N'},
        {'H','P','O','L','A','N','O'}
    };
    std::cout<<s.exist(a, "POLAND")<<std::endl;
}
