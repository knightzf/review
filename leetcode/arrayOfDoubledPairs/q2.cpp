#include "header.h"

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        vector<int> pos, neg, zero;
        for(int i : A)
        {
            if(i > 0) pos.push_back(i);
            else if(i < 0) neg.push_back(-i);
            else zero.push_back(i);
        }

        if(pos.size() % 2 != 0 || neg.size() % 2 != 0 || zero.size() % 2 != 0) return false;
        
        auto f = [](vector<int>& v)
        {
            multiset<int> s(v.begin(), v.end());
            while(!s.empty())
            {
                int t = *s.rbegin();
                if(t % 2 != 0) return false;
                if(s.count(t / 2) == 0) return false;
                s.erase(s.equal_range(t).first);
                s.erase(s.equal_range(t / 2).first);
            }
            return true;
        };

        return f(pos) && f(neg);
    }
};

int main()
{
    Solution s;
    vector<int> a{4,-2,2,-4};
    cout<<s.canReorderDoubled(a)<<endl;
}
