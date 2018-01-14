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
    vector<int> partitionLabels(string S) {
        vector<int> res;

        int n = S.size();
        if(n == 0) return res;

        std::unordered_map<char, std::pair<int, int>> charMap;
        for(int i = 0; i < n; ++i)
        {
            char c = S[i];
            if(charMap.find(c) == charMap.end())
            {
                charMap[c] = std::make_pair(i, i);
            }
            else
            {
                auto& p = charMap[c];
                p.second = i;
            }
        }

        int startIdx = 0;
        int endIdx = 0;
        for(int i = 0; i < n;)
        {
            char c = S[i];
            endIdx = charMap[c].second;

            for(int j = i + 1; j <= endIdx; ++j)
            {
                char d = S[j];
                if(charMap[d].second > endIdx)
                {
                    endIdx = charMap[d].second;
                }
            }

            res.push_back(endIdx - startIdx + 1);
            i = endIdx + 1;
            startIdx = i;
        }

        return res;
    }
};

int main() {
    Solution s;
    const auto& a = s.partitionLabels("ababcbacadefegdehijhklij");
    for(auto i : a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
