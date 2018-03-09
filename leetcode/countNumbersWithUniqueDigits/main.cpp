#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
#include <iterator>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            res += cnt(i);
        }

        return res;
    }
    int cnt(int i)
    {
        if(i == 1) return 10;

        int res = 1;
        for(int j = 0; j < i; ++j)
        {
            if(j == 0) res *= 9;
            else res *= (10 - j);
        }

        return res;
    }
};


int main() {
    Solution s;

}
