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
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int n = S.size();
        if(n == 0) return vector<string>{""};

        impl(S, 0, n, res);

        return res;
    }

    void impl(string& s, int startIdx, int endIdx, vector<string>& res)
    {
        while(startIdx < endIdx && !std::isalpha(s[startIdx])) ++startIdx;
        if(startIdx == endIdx)
        {
            res.push_back(s);
            return;
        }

        impl(s, startIdx + 1, endIdx, res);

        char c = s[startIdx];
        if(c >= 'a' && c <='z')
        {
            c = std::toupper(c);
        }
        else
        {
            c = std::tolower(c);
        }

        s[startIdx] = c;
        impl(s, startIdx + 1, endIdx, res);
    }
};

int main() {
    Solution s;
    const auto& r = s.letterCasePermutation("a1b2");
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
