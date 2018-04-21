#include "header.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        impl(0, n, res, true);
        return res;
    }

    void impl(int base, int n, vector<int>& res, bool flag = false)
    {
        for(int i = (flag ? 1 : 0); i < 10; ++i)
        {
            if(base + i <= n)
            {
                res.push_back(base + i);
            }

            if((base + i) * 10 <= n)
            {
                int t = (base + i) * 10;
                impl(t, n, res);
            }
        }
    }
};

int main()
{
    Solution s;
    const auto& r = s.lexicalOrder(100);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
