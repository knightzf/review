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
    int numJewelsInStones(string J, string S) {
        std::unordered_set<char> s(J.begin(), J.end());

        int cnt = 0;
        for(char c : S)
        {
            if(s.find(c) != s.end()) ++cnt;
        }

        return cnt;
    }
};


int main() {
    Solution s;
}
