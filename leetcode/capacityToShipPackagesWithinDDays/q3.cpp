#include "header.h"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        vector<int> total(n + 1, 0);
        for(int i = 0; i < n; ++i)
        {
            total[i + 1] = total[i] + weights[i];
        }

        function<bool(int)> validate = [&](int size)
        {
            int cnt = 0;
            for(int i = 0; i < n + 1;)
            {
                auto iter = upper_bound(total.begin() + i, total.end(), total[i] + size);
                --iter;
                i = distance(total.begin(), iter);
                ++cnt;
                if(cnt > D) 
                {
                    return false;
                }
                if(i == n) break;
            }
            return true;
        };

        int low = 1, high = total[n];
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(validate(mid))
            {
                high = mid;
            }
            else low = mid + 1;
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    cout<<s.shipWithinDays(a, 5)<<endl;
}

