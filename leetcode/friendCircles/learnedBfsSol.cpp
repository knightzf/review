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

using namespace std;

class Solution {
public:

    int findCircleNum(vector<vector<int>>& M)
    {
        int n = M.size();
        std::vector<bool> visitVec(n, false);

        int count = 0;

        for(int i = 0; i < n; ++i)
        {
            if(!visitVec[i])
            {
                bfs(M, visitVec, i);
                ++count;
            }
        }

        return count;
    }

    void bfs(vector<vector<int>>& M, vector<bool>& visitVec, int i)
    {
        std::queue<int> q;
        q.push(i);

        while(!q.empty())
        {
            int currentNode = q.front();
            q.pop();

            visitVec[currentNode] = true;

            for(int j = 0; j < M[currentNode].size(); ++j)
            {
                if(M[currentNode][j] && !visitVec[j])
                {
                    q.push(j);
                }
            }
        }
    }

};

int main()
{
    Solution s;
    vector<vector<int>> a{
        {1,0,0,0,1,1,0,1,0,0,0,1,0,0,0},
        {0,1,0,0,1,0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0,0,0,1,1,0},
        {0,0,0,1,0,0,0,0,0,0,0,1,1,1,0},
        {1,1,1,0,1,0,0,0,0,0,1,0,0,0,0},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
        {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,1,0,0,1,0},
        {1,0,0,1,0,0,0,0,0,0,0,1,1,0,0},
        {0,0,1,1,0,0,0,0,0,0,0,1,1,0,0},
        {0,0,1,1,0,0,0,0,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,1}
        };

    std::cout<<s.findCircleNum(a)<<std::endl;
}
