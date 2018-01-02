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

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        for(auto i : intervals)
        {
            std::cout<<i[0]<<" "<<i[1]<<"|";
        }
        std::cout<<std::endl;
        int n = intervals.size(), ans = 0, p1 = -1, p2 = -1;
        for (int i = 0; i < n; i++) {
            // current p1, p2 works for intervals[i]
            if (intervals[i][0] <= p1) continue;
            // Neither of p1, p2 works for intervals[i]
            // replace p1, p2 by ending numbers
            if (intervals[i][0] > p2) {
                ans += 2;
                p2 = intervals[i][1];
                p1 = p2-1;
            }
            // only p2 works;
            else {
                ans++;
                p1 = p2;
                p2 = intervals[i][1];
            }
            std::cout<<p1<<" "<<p2<<std::endl;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{2, 3}, {1, 4}, {2, 5}, {3, 5}};
    s.intersectionSizeTwo(a);
}
