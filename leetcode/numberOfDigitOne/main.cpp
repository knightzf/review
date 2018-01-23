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
    int countDigitOne(int n) {
        int count = 0;
        for(int i = 1; i < n; i *= 10)
        {
            int a = n / i; int b = n % i;

            count += (a + 8) / 10 * i + (b % 10 == 1) * (b + 1);
        }

        return count;
    }
};

int main() {
    Solution s;
}
