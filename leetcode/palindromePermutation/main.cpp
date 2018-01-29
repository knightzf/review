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
    bool canPermutePalindrome(string s) {
        int n = s.size();
        if(n < 2) return true;

        std::unordered_map<char, int> m;
        for(auto c : s)
        {
            ++m[c];
        }

        if(n % 2 == 0)
        {
            for(const auto& p : m)
            {
                if(p.second % 2 != 0) return false;
            }
        }
        else
        {
            int oddCount = 0;
            for(const auto& p : m)
            {
                if(p.second % 2 != 0) ++oddCount;
                if(oddCount > 1) return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
}
