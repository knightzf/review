#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> init = board[0];
        init.insert(init.end(), board[1].begin(), board[1].end());

        return impl(init);
    }

    int impl(const std::vector<int>& v)
    {
        static std::vector<int> goal{1, 2, 3, 4, 5, 0};
        static std::unordered_map<int, vector<int>> moves{
            {0, {1, 3}},
            {1, {0, 2, 4}},
            {2, {1, 5}},
            {3, {0, 4}},
            {4, {1, 3, 5}},
            {5, {2, 4}},
        };

        std::set<std::vector<int>> visited;

        std::queue<vector<int>> q;
        q.push(v);

        int qsize = q.size();
        int steps = 0;

        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                const auto& f = q.front();
                if(f == goal)
                {
                    return steps;
                }

                int zeroIdx = 0;
                for(int j = 0; j < 6; ++j)
                {
                    if(f[j] == 0)
                    {
                        zeroIdx = j;
                        break;
                    }
                }

                for(const auto& m : moves[zeroIdx])
                {
                    auto t = f;
                    std::swap(t[zeroIdx], t[m]);
                    /*for(int j = 0; j < 6; ++j)
                    {
                        std::cout<<t[j]<<" ";
                    }
                    std::cout<<std::endl;*/
                    if(visited.find(t) == visited.end())
                    {
                        visited.insert(t);
                        q.push(t);
                    }
                }
                q.pop();
            }

            qsize = q.size();
            ++steps;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{1, 2, 3}, {4, 0, 5}};
    vector<vector<int>> b{{1, 2, 3}, {5, 4, 0}};
    vector<vector<int>> c{{4, 1, 2}, {5, 0, 3}};
    vector<vector<int>> d{{3, 2, 4}, {1, 5, 0}};
    std::cout<<s.slidingPuzzle(a)<<std::endl;
    std::cout<<s.slidingPuzzle(b)<<std::endl;
    std::cout<<s.slidingPuzzle(c)<<std::endl;
    std::cout<<s.slidingPuzzle(d)<<std::endl;
}
