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

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        impl(result, n, k, 1);

        return result;
    }

private:

    void impl(vector<vector<int>>& result, int n, int k, int start)
    {
        if(k == 0)
        {
            return;
        }

        if(k == 1)
        {
            for(int i = start; i <= n; ++i)
            {
                result.push_back(std::vector<int>{i});
            }
            return;
        }

        for(int i = start; i <= n; ++i)
        {
            vector<vector<int>> t;
            impl(t, n, k - 1, i + 1);
            for(auto item : t)
            {
                item.push_back(i);
                result.push_back(item);
            }
        }
    }
};

int main()
{
    Solution sol;
    const auto& r = sol.combine(4, 3);
    for(const auto& i : r)
    {
        for(const auto& j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
