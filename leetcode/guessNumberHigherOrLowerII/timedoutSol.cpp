#include "header.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        return impl(1, n);
    }

    int impl(int l, int r)
    {
        static unordered_map<int, int> m;
        if(l == r) return 0;
        if(l + 1 == r) return l;
        if(l == 1 && m.find(r) != m.end()) return m[r];

        int res = INT_MAX;
        for(int i = l + (r - l) / 2; i < r; ++i)
        {
            res = min(res, i + max(impl(l, i - 1), impl(i + 1, r)));
        }

        if(l == 1) m.emplace(r, res);
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.getMoneyAmount(4)<<std::endl;
    std::cout<<s.getMoneyAmount(5)<<std::endl;
    std::cout<<s.getMoneyAmount(7)<<std::endl;
}
