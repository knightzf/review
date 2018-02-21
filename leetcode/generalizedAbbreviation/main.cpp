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
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        if(n == 0) return {word};

        vector<string> res;
        impl(word, "", 0, n, res);
        return res;
    }

    void impl(const std::string& word, const std::string& prefix, int startIdx, int endIdx, vector<string>& res)
    {
        if(startIdx == endIdx)
        {
            res.push_back(prefix);
            return;
        }

        for(int i = startIdx + 1; i <= endIdx; ++i)
        {
            if(prefix.empty() || std::isdigit(prefix.back()))
                impl(word, prefix + word.substr(startIdx, i - startIdx), i, endIdx, res);
            if(prefix.empty() || !std::isdigit(prefix.back()))
                impl(word, prefix + std::to_string(i - startIdx), i, endIdx, res);
        }
    }
};

int main() {
    Solution s;
    const auto& r = s.generateAbbreviations("word");
    for(const auto& i : r)
    {
        std::cout<<i<<std::endl;
    }
}
