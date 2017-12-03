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

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int res = 0;

        vector<vector<int>> m(matrix.size(), std::vector<int>());

        for(int i = 0; i < matrix.size(); ++i)
        {
            std::vector<int> v;
            if(i == 0)
            {
                for(auto c : matrix[i])
                {
                    int value = c - '0';
                    m[i].push_back(value);
                }
            }
            else
            {
                for(int j = 0; j < matrix[i].size(); ++j)
                {
                    int value = matrix[i][j] == '0' ? 0 : m[i - 1][j] + 1;
                    m[i].push_back(value);
                }
            }

            res = std::max(res, maxRectangle(m[i]));
        }

//        for(const auto& i : m)
//        {
//            for(const auto& j : i)
//            {
//                std::cout<<j <<" ";
//            }
//            std::cout<<std::endl;
//        }
        return res;
    }
private:
    int maxRectangle(vector<int>& v)
    {
        int ret = 0;

        v.push_back(0);

        std::stack<int> s;

        for(int i = 0; i < v.size(); ++i)
        {
            while(!s.empty() && v[s.top()] >= v[i])
            {
                int value = v[s.top()];
                s.pop();

                int startIdx = s.empty() ? -1 : s.top();
                ret = std::max(ret, (i - startIdx - 1) * value);
            }
            s.push(i);
        }

        //std::cout<<"ret "<<ret<<std::endl;

        return ret;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> a {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    s.maximalRectangle(a);
}
