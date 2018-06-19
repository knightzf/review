#include "header.h"

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if(total % n != 0) return -1;
        int avg = total / n;

        long sum = 0;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += machines[i];
            int t = 0;
            if(sum > long(i + 1) * avg)
            {
                t = sum - long(i + 1) * avg;
                if(sum - machines[i] < long(i) * avg)
                    t += long(i) * avg - sum + machines[i];
            }
            else
            {
                t = long(i + 1) * avg - sum;
            }
            res = max(res, t);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{4,9,8,4,0};
    cout<<s.findMinMoves(a)<<endl;
}
