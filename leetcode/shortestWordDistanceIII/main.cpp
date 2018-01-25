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
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int minDis = n;
        if(word1 == word2)
        {
            int lastIdx = INT_MAX;
            for(int i = 0; i < n; ++i)
            {
                if(words[i] == word1)
                {
                    if(lastIdx != INT_MAX)
                    {
                        minDis = std::min(minDis, i - lastIdx);
                    }

                    lastIdx = i;
                }
            }
        }
        else
        {
            int index1 = INT_MAX, index2 = INT_MAX;
            for(int i = 0; i < n; ++i)
            {
                if(words[i] == word1)
                {
                    index1 = i;
                }

                if(words[i] == word2)
                {
                    index2 = i;
                }

                if(index1 != INT_MAX && index2 != INT_MAX)
                {
                    minDis = std::min(minDis, std::abs(index1 - index2));
                }
            }
        }

        return minDis;

    }
};

int main() {
    Solution s;
}
