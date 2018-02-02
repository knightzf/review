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
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(k == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k * k;

        int sameCount = k;
        int diffCount = k * k - k;
        for(int i = 2; i < n; ++i)
        {
            int t = diffCount;
            diffCount = sameCount * (k - 1) + diffCount * (k - 1);
            sameCount = t;
        }

        return sameCount + diffCount;
    }
};

int main() {
    Solution s;
}
