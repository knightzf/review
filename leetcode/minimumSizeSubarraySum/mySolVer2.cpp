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
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int sz = nums.size();
        std::vector<int> m; m.reserve(sz + 1);
        m.push_back(0);
        int sum = 0;
        for(int n : nums)
        {
            if(n >= s) return 1;
            sum += n;
            m.push_back(sum);
        }

        if(m.back() < s) return 0;

        int endIdx = findIdx(m, 0, sz + 1, s);
        int minLen = INT_MAX;

        for(int i = endIdx; i < sz + 1; ++i)
        {
            int startIdx = findIdx(m, 0, sz + 1, m[i] - s);
            minLen = min(minLen, m[startIdx] == m[i] - s ? i - startIdx : i - startIdx + 1);
            if(minLen == 2) return 2;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }

    int findIdx(vector<int>& m, int startIdx, int endIdx, int s)
    {
        while(startIdx < endIdx)
        {
            int midIdx = (startIdx + endIdx) / 2;
            if(m[midIdx] > s)
            {
                endIdx = midIdx;
            }
            else if(m[midIdx] < s)
            {
                startIdx = midIdx + 1;
            }
            else
            {
                return midIdx;
            }
        }

        return endIdx;
    }
};

int main() {
    Solution s;
    /*{
        vector<int> a{2, 3, 1, 2, 4, 3};
        std::cout<<s.minSubArrayLen(7, a)<<std::endl;
    }
    {
        vector<int> a{1, 2, 3, 4, 5};
        std::cout<<s.minSubArrayLen(15, a)<<std::endl;
    }*/
    {
        vector<int> a{1, 2, 3, 4, 5};
        std::cout<<s.minSubArrayLen(11, a)<<std::endl;
    }

}
