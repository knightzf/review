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

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if(board.empty() || board[0].empty())
        {
            return false;
        }

        if(word.empty())
        {
            return false;
        }

        int row = board.size();
        int col = board[0].size();

        typedef std::unordered_map<char, std::vector<std::pair<int,int>>> CharMap;

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

        /*for(const auto& i : charMap)
        {
            std::cout<<i.first<<std::endl;
            for(const auto& j : i.second)
            {
                std::cout<<"    "<<j.first<<" "<<j.second<<std::endl;
            }
        }*/

        typedef std::stack<std::pair<std::pair<int, int>, int>> Stack;
        typedef std::map<std::pair<int, int>, int> LocIdxMap;
        typedef std::map<int, std::pair<int, int>> IdxLocMap;

        int n = word.size();

        if(charMap.find(word[0]) != charMap.end())
        {
            Stack s;
            LocIdxMap locIdxMap;
            IdxLocMap idxLocMap;

            for(const auto& p : charMap[word[0]])
            {
                s.push(std::make_pair(p, 0));
            }

            while(!s.empty())
            {
                auto p = s.top();
                s.pop();

                //std::cout<<p.second<<std::endl;
                if(p.second == n - 1)
                {
                    return true;
                }

                if(idxLocMap.find(p.second) == idxLocMap.end())
                {
                    locIdxMap[p.first] = p.second;
                    idxLocMap[p.second] = p.first;
                }
                else
                {
                    auto iter = idxLocMap.find(p.second);

                    for(auto i = iter; i != idxLocMap.end(); ++i)
                    {
                        locIdxMap.erase(i->second);
                    }
                    locIdxMap[p.first] = p.second;

                    idxLocMap.erase(iter, idxLocMap.end());
                    idxLocMap[p.second] = p.first;
                }

                auto loc = p.first;
                auto idx = p.second + 1;

                auto f = [&](int i, int j)
                {
                    if(board[i][j] == word[idx] &&
                       locIdxMap.find(std::make_pair(i, j)) == locIdxMap.end())
                    {
                        s.push(std::make_pair(std::make_pair(i, j), idx));
                    }
                };

                if(loc.first > 0)
                {
                    f(loc.first - 1, loc.second);
                }

                if(loc.first < row - 1)
                {
                    f(loc.first + 1, loc.second);
                }

                if(loc.second > 0)
                {
                    f(loc.first, loc.second - 1);
                }

                if(loc.second < col - 1)
                {
                    f(loc.first, loc.second + 1);
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> a{
        vector<char>{'A', 'B', 'C', 'E'},
        vector<char>{'S', 'F', 'C', 'S'},
        vector<char>{'A', 'D', 'E', 'E'}
    };
    std::cout<<sol.exist(a, "ABCCED")<<std::endl;
    std::cout<<sol.exist(a, "SEE")<<std::endl;
    std::cout<<sol.exist(a, "ABCB")<<std::endl;

    vector<vector<char>> b{
        vector<char>{'A', 'B', 'C', 'E'},
        vector<char>{'S', 'F', 'E', 'S'},
        vector<char>{'A', 'D', 'E', 'E'}
    };
    std::cout<<sol.exist(b, "ABCEFSADEESE")<<std::endl;
}
