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
    int bulbSwitch(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            int toggleTimes = 0;
            for(int j = 1; j <= i; ++j)
            {
                if(i % j == 0) ++toggleTimes;
            }

            if(toggleTimes % 2 == 1) ++res;
        }

        return res;
    }
};

int main() {
    Solution s;
}
