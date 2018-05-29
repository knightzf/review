#include "header.h"

class Solution {
public:
    int magicalString(int n) {
        if(n == 0) return 0;
        vector<int> v{1, 2, 2};
        v.reserve(n);
        int i = 2, j = 2;
        int cnt = 1;
        while(j < n - 1)
        {
            if(v[i] == 1)
            {
                if(v[j] == 2)
                {
                    v.push_back(1);
                    ++cnt;
                }
                else
                {
                    v.push_back(2);
                }
                ++j;
            }
            else
            {
                if(v[j] == 2)
                {
                    v.push_back(1);
                    v.push_back(1);
                    if(j + 2 < n) cnt += 2;
                    else ++cnt;
                }
                else
                {
                    v.push_back(2);
                    v.push_back(2);
                }
                j += 2;
            }
            ++i;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    cout<<s.magicalString(7)<<endl;
}
