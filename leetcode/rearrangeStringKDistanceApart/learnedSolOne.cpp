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
    string rearrangeString(string s, int k) {
        if(k < 2) return s;

        std::vector<int> v(26);
        for(int i = 0; i < s.size(); ++i)
        {
            ++v[s[i] - 'a'];
        }

        std::vector<int> validIndices(26, 0);

        string res;

        for(int i = 0; i < s.size(); ++i)
        {
            int nextCharIdx = getNextCharIdx(v, validIndices, i);
            if(nextCharIdx == -1) return "";

            res += 'a' + nextCharIdx;
            --v[nextCharIdx];
            validIndices[nextCharIdx] += k;
        }

        return res;
    }

    int getNextCharIdx(const std::vector<int>& v, const std::vector<int>& validIndices, int idx)
    {
        int nextCharIdx = -1;
        int maxCharCnt = INT_MIN;
        for(int i = 0; i < 26; ++i)
        {
            if(v[i] > 0 && idx >= validIndices[i])
            {
                if(v[i] > maxCharCnt)
                {
                    nextCharIdx = i;
                    maxCharCnt = v[i];
                }
            }
        }
        return nextCharIdx;
    }
};

int main() {
    Solution s;
    std::cout<<s.rearrangeString("aabbcc", 2)<<std::endl;

}
