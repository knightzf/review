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
#include <iterator>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 0) return 0;
        long i = 1, j = n + 1;
        while(i < j)
        {
            long m = (i + j) / 2;
            if(isBadVersion(m))
            {
                j = m;
            }
            else
            {
                i = m + 1;
            }
        }

        return isBadVersion(j - 1) ? j - 1 : j;
    }
};

int main() {
    Solution s;
}
