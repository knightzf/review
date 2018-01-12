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

class Solution {
public:
    void reverseWords(vector<char>& str) {
        int n = str.size();
        if(n == 0) return;

        std::reverse(str.begin(), str.end());

        int startIdx = 0;
        for(int i = 0; i <= n; ++i)
        {
            if(i == n || str[i] == ' ')
            {
                std::reverse(str.begin() + startIdx, str.begin() + i);
                startIdx = i + 1;
            }
        }
    }
};


int main() {
    Solution s;
}
