#include "header.h"

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> bloomTime(n + 1);
        for(int i = 0; i < n; ++i)
        {
            bloomTime[flowers[i]] = i + 1; 
        }

        int res = INT_MAX;
        int left = 1, right = k + 2;
        for(int i = 1; right < n + 1; ++i)
        {
            if(bloomTime[i] < bloomTime[left] || bloomTime[i] <= bloomTime[right])
            {
                if(i == right)
                {
                    res = min(res, max(bloomTime[left], bloomTime[right]));
                }

                left = i;
                right = i + k + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 3, 2};
    cout<<s.kEmptySlots(a, 1)<<endl;
}
