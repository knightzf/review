#include "header.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int, std::greater<int>> m;
        for(int i : stones) m.insert(i);
        while(m.size() >= 2) {
            auto iter = m.begin();
            auto jter = iter; ++jter;
            int x = *iter, y = *jter;
            m.erase(iter);
            m.erase(jter);
            if(x > y) m.insert(x - y);
        }

        if(m.empty()) return 0;
        return *m.begin();
    }
};

int main()
{
    Solution s;
    vector<int> a{1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98};
    cout<<s.lastStoneWeight(a)<<endl;
}
