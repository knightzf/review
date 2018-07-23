#include "header.h"

class Solution {
public:
    int findIntegers(int num) {
        static unordered_map<int, int> m{{0, 1}, {1, 2}};

        if(m.count(num) == 0)
        {
            int len = log2(num) + 1;
            bool shouldBreak = false;
            int res = 0;
            for(int i = 0; i < len; ++i)
            {
                if(shouldBreak) break;
                if(num & (1 << (len - i - 1)))
                {
                    res += findIntegers((1 << len - i - 1) - 1);

                    if(i != 0 && num & (1 << (len - i)))
                    {
                        shouldBreak = true;
                    }
                }
                else
                {
                    res += findIntegers(num & ((1 << len - i) - 1));
                    break;
                }
            }

            m[num] = res;
        }

        return m[num];
    }
};

string bin(int num)
{
    string res;
    while(num)
    {
        res += '0' + num % 2;
        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    Solution s;
    int res = 0;
    for(int i = 0; i < 2 << 5; ++i)
    {
        const auto& r = bin(i);
        //cout<<i<<" "<<r<<endl;
        if(r.find("11") == -1) ++res;
    }
    //cout<<res<<endl;
    cout<<s.findIntegers(100)<<endl;
    cout<<s.findIntegers(6)<<endl;
    cout<<s.findIntegers(5)<<endl;
    cout<<s.findIntegers(4)<<endl;
    cout<<s.findIntegers(3)<<endl;
    cout<<s.findIntegers(2)<<endl;
    cout<<s.findIntegers(1)<<endl;
}
