#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, priority_queue<int, vector<int>, greater<int>> > m;
        for (int x : nums) {
            int y = 1;
            if (m[x - 1].size()) {
                y += m[x - 1].top();
                m[x - 1].pop();
            }
            m[x].push(y);
        }
        
        for (auto it : m) {
            if (it.second.size() && it.second.top() < 3) return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1, 2, 3, 3, 4, 4, 5, 5};
    sol.isPossible(a);
	return 0;
}