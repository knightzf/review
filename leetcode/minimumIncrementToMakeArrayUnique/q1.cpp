#include "header.h"

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int, int> m;
        for(int i : A)
            ++m[i];
        int res = 0;
        for(auto& p : m)
        {
            if(p.second > 1)
            {
                res += p.second - 1;
                m[p.first + 1] += p.second - 1;
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}
