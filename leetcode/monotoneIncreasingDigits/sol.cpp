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
    int monotoneIncreasingDigits(int N)
    {
        std::vector<int> v;
        while(N)
        {
            v.push_back(N % 10);
            N = N / 10;
        }

        int firstNineIdx = -1;

        for(int i = 0; i < v.size(); ++i)
        {
            if(i != v.size() - 1 && v[i] < v[i + 1])
            {
                v[i] = 9;
                v[i + 1] -= 1;

                firstNineIdx = i;
            }
        }

        if(firstNineIdx != -1 && firstNineIdx != 0)
        {
            for(int i = 0; i < firstNineIdx; ++i)
            {
                v[i] = 9;
            }
        }

        for(auto i : v)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        int res = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            res += std::pow(10, i) * v[i];
        }

        std::cout<<res<<std::endl;

        return res;
    }
};

int main()
{
    Solution s;
    s.monotoneIncreasingDigits(989998);
}
