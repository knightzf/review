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
    typedef std::unordered_map<char, std::vector<std::pair<int,int>>> CharMap;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        unordered_set<string> notfound;

        if(board.empty() || board[0].empty())
        {
            return vector<string>();
        }

        int row = board.size();
        int col = board[0].size();

        CharMap charMap;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                char c = board[i][j];
                if(charMap.find(c) == charMap.end())
                {
                    charMap[c] = std::vector<std::pair<int,int>>{std::make_pair(i, j)};
                }
                else
                {
                    charMap[c].push_back(std::make_pair(i, j));
                }
            }
        }

        for(const auto& word : words)
        {
            if(notfound.find(word) != notfound.end())
            {
                continue;
            }

            if(res.find(word) == res.end())
            {
                if(exist(board, charMap, word, row, col))
                {
                    res.insert(word);
                }
                else
                {
                    notfound.insert(word);
                }
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    bool exist(vector<vector<char>>& board,
               CharMap& charMap,
               const string& word,
               int row,
               int col)
    {
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        if(charMap.find(word[0]) != charMap.end())
        {
            for(const auto& p : charMap[word[0]])
            {
                visited[p.first][p.second] = true;
                if(impl(board, row, col, visited, word, 1, p.first, p.second))
                {
                    return true;
                }
                visited[p.first][p.second] = false;
            }
        }

        return false;
    }

    bool impl(vector<vector<char>>& board,
              int row,
              int col,
              vector<vector<bool>>& visited,
              const std::string& word,
              int idx,
              int i,
              int j)
    {
        if(idx == word.size()) return true;

        char c = word[idx];

        if(i > 0 && board[i - 1][j] == c && visited[i - 1][j] == false)
        {
            visited[i - 1][j] = true;
            if(impl(board, row, col, visited, word, idx + 1, i - 1, j)) return true;
            visited[i - 1][j] = false;
        }

        if(i < row - 1 && board[i + 1][j] == c && visited[i + 1][j] == false)
        {
            visited[i + 1][j] = true;
            if(impl(board, row, col, visited, word, idx + 1, i + 1, j)) return true;
            visited[i + 1][j] = false;
        }

        if(j > 0 && board[i][j - 1] == c && visited[i][j - 1] == false)
        {
            visited[i][j - 1] = true;
            if(impl(board, row, col, visited, word, idx + 1, i, j - 1)) return true;
            visited[i][j - 1] = false;
        }

        if(j < col - 1 && board[i][j + 1] == c && visited[i][j + 1] == false)
        {
            visited[i][j + 1] = true;
            if(impl(board, row, col, visited, word, idx + 1, i, j + 1)) return true;
            visited[i][j + 1] = false;
        }

        return false;
    }
};

int main() {
    Solution s;
}
