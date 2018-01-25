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
    int shortestDistance(vector<string>& words, string word1, string word2) {
        std::map<std::string, std::set<int>> m;
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            m[words[i]].insert(i);
        }

        const auto& r1 = m[word1];
        auto& r2 = m[word2];

        int minDis = n;

        for(auto i : r1)
        {
            if(i < *r2.begin())
            {
                minDis = std::min(minDis, *r2.begin() - i);
            }
            else if(i > *r2.rbegin())
            {
                minDis = std::min(minDis, i - *r2.rbegin());
            }
            else
            {
                const auto& p = r2.insert(i);
                auto q = p.first;
                --q;
                minDis = std::min(minDis, *(p.first) - *q);

                q = p.first;
                ++q;
                minDis = std::min(minDis, *q - *(p.first));

                r2.erase(i);
            }
        }

        return minDis;
    }
};

int main() {
    Solution s;
}
