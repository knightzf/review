#include "header.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> v(2, 0);
        for(int b : bills)
        {
            if(b == 5)
                ++v[0];
            else if(b == 10)
            {
                if(v[0] == 0) return false;
                --v[0];
                ++v[1];
            }
            else if(b == 20)
            {
                if(v[0] == 0) return false;
                if(v[1] > 0)
                {
                    --v[1];
                    --v[0];
                }
                else
                {
                    if(v[0] < 3) return false;
                    v[0] -= 3;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> a{5,5,10};
    cout<<s.lemonadeChange(a)<<endl;
}
