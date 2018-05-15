#include "header.h"

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int, int> m;
        for(int size : s)
            ++m[size];

        int res = 0;
        for(int greed : g)
        {
            auto iter = m.lower_bound(greed);
            if(iter != m.end())
            {
                ++res;
                --iter->second;
                if(iter->second == 0)
                    m.erase(iter);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
