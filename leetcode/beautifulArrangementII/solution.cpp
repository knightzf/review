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

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k)
    {
        std::vector<int> result;

        if(k > 1)
        {
            int a = k + 1;
            int b = 1;

            while(a > b)
            {
                result.push_back(a);
                result.push_back(b);
                --a;
                ++b;
            }

            if(a == b)
            {
                result.push_back(a);
            }

            for(int i = k + 2; i < n + 1; ++i)
            {
                result.push_back(i);
            }
        }
        else
        {
            for(int i = 1; i < n + 1; ++i)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    const auto & a = sol.constructArray(10, 6);
    for(const auto& i : a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    for(size_t i = 1; i < a.size(); ++i)
    {
        std::cout<<std::abs(a[i] - a[i - 1])<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
