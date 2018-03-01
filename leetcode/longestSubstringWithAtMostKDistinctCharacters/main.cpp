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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        vector<int> m(256, 0);
        int cnt = 0;
        int n = s.size();
        int startIdx = 0;
        int res = 0;

        for(int i = 0; i < n; ++i)
        {
            if(cnt < k || (cnt == k && m[s[i]]))
            {
                char c = s[i];
                if(m[c] == 0) ++cnt;
                ++m[c];
                res = max(res, i - startIdx + 1);
            }
            else
            {
                while(cnt == k)
                {
                    char c = s[startIdx++];
                    --m[c];
                    if(m[c] == 0) --cnt;
                }
                ++m[s[i]];
                ++cnt;
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    //std::cout<<s.lengthOfLongestSubstringKDistinct("eceba", 2)<<std::endl;
    std::cout<<s.lengthOfLongestSubstringKDistinct("nfhiexxjrtvpfhkrxcutexxcodfioburrtjefrgwrnqtyzelvtpvwdvvpsbudwtiryqzzy", 25)<<std::endl;
}
