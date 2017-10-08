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
    bool hasAlternatingBits(int n)
    {
        int digit = n % 2;
        n = n / 2;

        while(true)
        {
            if(n == 0)
            {
                break;
            }

            if(n % 2 == digit)
            {
                return false;
            }
            else
            {
                digit = n % 2;
                n = n /2;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.hasAlternatingBits(5);
    std::cout<<sol.hasAlternatingBits(7);
    return 0;
}
