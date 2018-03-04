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
    int numMatchingSubseq(string S, vector<string>& words) {
        std::vector<std::set<int>> m(26);
        for(int i = 0; i < S.size(); ++i)
        {
            m[S[i] - 'a'].insert(i);
        }

        int res = 0;
        for(const auto& w : words)
        {
            int prevIdx = -1;
            bool found = true;
            for(int i = 0; i < w.size(); ++i)
            {
                int idx = w[i] - 'a';
                if(m[idx].upper_bound(prevIdx) != m[idx].end())
                {
                    prevIdx = *(m[idx].upper_bound(prevIdx));
                }
                else
                {
                    found = false;
                    break;
                }
            }
            if(found == true)
                ++res;
        }

        return res;
    }
};



int main() {
    Solution s;
}
