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
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                    if(a.first == b.first) return a.second > b.second;
                    return a.first < b.first;
                  });

        vector<int> dp(envelopes.size());
        int len = 0;
        for(const auto& p : envelopes)
        {
            int i = 0, j = len;
            while(i != j)
            {
                int m = (i + j) / 2;
                if(dp[m] < p.second)
                {
                    i = m + 1;
                }
                else
                {
                    j = m;
                }
            }

            dp[i] = p.second;
            if(i == len) ++len;
        }

        return len;
    }
};


int main() {
    Solution s;
    //vector<pair<int, int>> a{{5, 4},{6, 4},{6, 7},{2, 3}};
    vector<pair<int, int>> a{{8,18},{4,14},{16,1},{9,11},{14,15},{12,19},{2,15},{4,4},{18,3},{20,8},{19,18},{18,2},{1,10},{12,1},{10,16},{1,1},{3,19}};
    std::cout<<s.maxEnvelopes(a)<<std::endl;
}
