#include "header.h"

class Solution {
public:
    int countArrangement(int N) {
        vector<bool> v(N + 1, true);
        return impl(v, 1, N);
    }

    int impl(vector<bool>& v, int num, int n)
    {
        if(num == n + 1) return 1;

        int res = 0;
        bool found = false;
        for(int i = 1; i <= n; ++i)
        {
            if((num % i == 0 || i % num == 0) && v[i] == true)
            {
                found = true;

                v[i] = false;
                if(int r = impl(v, num + 1, n); r > 0)
                    res += r;
                v[i] = true;
            }
        }
        if(!found) return 0;
        return res;
    }
};

int main()
{
    Solution s;
}
