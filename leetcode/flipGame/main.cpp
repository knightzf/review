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
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.size();
        for(int i = 0; i < n - 1; ++i)
        {
            if(s[i] == '+' && s[i + 1] == '+')
            {
                string t = s;
                t[i] = '-';
                t[i + 1] = '-';
                res.emplace_back(t);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
}
