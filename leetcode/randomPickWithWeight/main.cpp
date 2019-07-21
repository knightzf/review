#include "header.h"

class Solution {
private:
    map<int, int> m;
    int sum = 0;
public:
    Solution(vector<int>& w) {
        for(int i = 0, n = w.size(); i < n; ++i) {
            sum += w[i];
            m[sum] = i;
        }
    }

    int pickIndex() {
        int r = rand() % sum;
        auto iter = m.upper_bound(r);
        return iter->second;
    }
};


int main()
{
    //Solution s;
}