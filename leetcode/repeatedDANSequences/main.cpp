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
    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map<std::string, int> countMap;

        for(int i = 0; i < s.size() - 9; ++i)
        {
            ++countMap[s.substr(i, 10)];
        }

        vector<string> res;

        for(const auto& p : countMap)
        {
            if(p.second > 1)
            {
                res.push_back(p.first);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
}
