#include "header.h"

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> a, b;
        for(int i = 0; ; ++i)
        {
            int t = pow(x, i);
            if(t >= bound) break;
            if(!a.empty() && t <= a.back()) break;
            a.push_back(t);
        }

        for(int i = 0; ; ++i)
        {
            int t = pow(y, i);
            if(t >= bound) break;
            if(!b.empty() && t <= b.back()) break;
            b.push_back(t);
        }

        unordered_set<int> s;
        for(int i = 0; i < a.size(); ++i)
        {
            for(int j = 0; j < b.size(); ++j)
            {
                if(a[i] + b[j] <= bound) s.insert(a[i] + b[j]);
                else break;
            }
        }

        return vector<int>(s.begin(), s.end());
    }
};

int main()
{
    Solution s;
}
