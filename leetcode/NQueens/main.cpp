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

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        std::queue<std::pair<int, vector<string>>> q;

        for(int i = 0; i < n; ++i)
        {
            vector<string> t(n, std::string(n, '.'));
            t[0][i] = 'Q';

            q.push(std::make_pair(0, t));
        }

        vector<vector<string>> result;

        while(!q.empty())
        {
            const auto& preV = q.front();
            for(int i = 0; i < n; ++i)
            {
                auto newV = preV.second;
                int idx = preV.first + 1;
                if(idx <= n - 1)
                {
                    newV[idx][i] = 'Q';
                }
                else
                {
                    idx = n - 1;
                }

                if(isValid(newV, idx))
                {
                    if(idx != n - 1)
                    {
                        q.push(std::make_pair(idx, newV));
                    }
                    else
                    {
                        result.push_back(newV);
                    }
                }
            }
            q.pop();
        }

        return result;
    }

private:
    bool isValid(const std::vector<std::string>& v, int idx)
    {
        for(int i = 0; i <= idx; ++i)
        {
            auto idx = v[i].find('Q');
            if(idx != std::string::npos)
            {
                if(!isValid(v, i, idx))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(const std::vector<std::string>& v, int i, int j)
    {
        int n = v.size();

        for(int k = 0; k < i; ++k)
        {
            if(k != i && v[k][j] == 'Q')
                return false;
        }

        int tI = i;
        int tJ = j;

        while(tI > 0 && tJ > 0)
        {
            if(v[--tI][--tJ] == 'Q')
                return false;
        }

        tI = i;
        tJ = j;

        while(tI < n - 1 && tJ > 0)
        {
            if(v[++tI][--tJ] == 'Q')
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    const auto& b = sol.solveNQueens(1);

    for(const auto& i : b)
    {
        for(const auto& j : i)
        {
            std::cout<<j<<std::endl;
        }
        std::cout<<"------"<<std::endl;
    }
    return 0;
}
