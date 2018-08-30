#include "header.h"

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> blooms;
        for(int i = 0, n = flowers.size(); i < n; ++i)
        {
            int pos = flowers[i];
            if(!blooms.empty())
            {                
                auto upper = blooms.upper_bound(pos);
                if(upper != blooms.end()) {
                    if(*upper - pos == k + 1) return i + 1;
                    if(upper != blooms.begin())
                    {
                        --upper;
                        if(pos - *upper == k + 1) return i + 1;
                    }
                }
                else {
                    if(pos - *blooms.rbegin() == k + 1) return i + 1;
                }
            }

            blooms.insert(pos);
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 3, 2};
    cout<<s.kEmptySlots(a, 1)<<endl;
}
