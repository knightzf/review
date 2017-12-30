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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        n = gas.size();

        if(n == 0)
        {
            return -1;
        }

        for(int i = 0; i < n;)
        {
            //std::cout<<"i "<<i<<std::endl;
            int start = i;
            int j = start;
            int tank = gas[start];

            while(tank >= cost[j])
            {
                tank -= cost[j];
                j = next(j);
                tank += gas[j];

                if(j == start)
                {
                    return start;
                }
            }

            if(j < start)
            {
                return -1;
            }
            else if(j > start)
            {
                i = j;
            }
            else
            {
                ++i;
            }
        }

        return -1;
    }

    int next(int idx)
    {
        if(idx == n - 1)
        {
            return 0;
        }

        return idx + 1;
    }

private:
    int n;
};

int main()
{
    Solution s;
    std::vector<int> a{2, 4};
    std::vector<int> b{3, 4};
    s.canCompleteCircuit(a, b);
}
