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
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n == 0) return 0;
        vector<int> binary(n);
        for(int i = 0; i < n; ++i)
        {
            int t = 0;
            for(int j = 0; j < words[i].size(); ++j)
            {
                t |= 1 << (words[i][j] - 'a');
            }
            binary[i] = t;
        }

        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if((binary[i] & binary[j]) == 0)
                {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> a{"abcw","baz","foo","bar","xtfn","abcdef"};
    std::cout<<s.maxProduct(a)<<std::endl;
}
