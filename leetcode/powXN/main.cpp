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
    double myPow(double x, int n) {
        return impl(x, n);
    }

    double impl(double x, long n)
    {
        if(n == 0) return 1;
        if(n < 0) return 1 / impl(x, -n);

        double res = 1;
        double t = x;
        while(n)
        {
            if(n & 1)
                res *= t;
            n >>= 1;
            t = t * t;
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.myPow(1, -2147483648)<<std::endl;;
}
