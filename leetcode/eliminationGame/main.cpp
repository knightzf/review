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
    int lastRemaining(int n)
    {
        if(n == 1) return 1;

        n = n % 2 == 1 ? n - 1 : n;

        int start = 1;
        int end = n;

        int diff = 1;

        bool left = true;

        while(start != end)
        {
            if(left)
            {
                start = start + diff;
            }
            else
            {
                end = end - diff;
            }

            diff *= 2;

            if(left)
            {
                int t = start;
                while(t < end)
                {
                    t += diff;
                }

                end = t > end ? t - diff : t;
            }
            else
            {
                int t = end;
                while(t > start)
                {
                    t -= diff;
                }

                start = t < start ? t + diff : t;
            }

            left = !left;

            //std::cout<<start<<" "<<end<<std::endl;
        }

        return start;
    }
};

int main()
{
    Solution s;
    std::cout<<s.lastRemaining(10)<<std::endl;
}
