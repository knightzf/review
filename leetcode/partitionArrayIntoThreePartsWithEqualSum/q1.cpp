#include "header.h"

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        unordered_map<int, set<int>> m;
        for(int i = 0; i < n; ++i)
        {
            sum += A[i];
            m[sum].insert(i);
        }

        if(sum % 3 != 0) return false;

        for(auto i : m[sum / 3])
        {
            int t = sum / 3 * 2;
            if(m[t].upper_bound(i) != m[t].end()) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
}
