#include "header.h"

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a % 1337 == 0) return 0;

        if(a > 1337) a %= 1337;
        vector<int> cache(11);
        cache[0] = 1;
        cache[1] = a;
        for(int i = 2; i < 11; ++i)
        {
            cache[i] = (cache[i - 1] * a) % 1337;
        }

        /*for(int i : cache)
            std::cout<<i<<" ";
        std::cout<<std::endl;
        //*/
        int res = 1;
        int prev = a;
        for(int i = b.size() - 1; i >= 0; --i)
        {
            if(i != b.size() - 1)
            {
                int t = 1;
                for(int j = 0; j < 10; ++j)
                {
                    t = (t * prev) % 1337;
                }
                prev = t;
            }

            if(b[i] != 0)
            {
                if(i != b.size() - 1)
                {
                    for(int j = 0; j < b[i]; ++j)
                    {
                        res = (res * prev) % 1337;
                    }
                }
                else
                {
                    res = (res * cache[b[i]]) % 1337;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{2, 0, 0};
    std::cout<<s.superPow(2147483647, a)<<std::endl;
}
