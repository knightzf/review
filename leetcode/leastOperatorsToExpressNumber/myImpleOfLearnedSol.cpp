#include "header.h"

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        vector<int> remainder;
        while(target)
        {
            remainder.push_back(target % x);
            target /= x;
        }

        int pos, neg;

        for(int i = 0; i < remainder.size(); ++i)
        {
            if(i == 0)
            {
                pos = remainder[i] * 2;
                neg = (x - remainder[i]) * 2;
            }
            else
            {
                int pos2 = min(pos + remainder[i] * i, neg + remainder[i] * i + i);
                int neg2 = min(pos + (x - remainder[i]) * i, neg + i + (x - remainder[i]) * i - 2 * i);
                pos = pos2;
                neg = neg2;
            }
        }

        return min(pos, (int)remainder.size() + neg) - 1;
    }
};

int main()
{
    Solution s;
    //cout<<s.leastOpsExpressTarget(3, 19)<<endl;
    cout<<s.leastOpsExpressTarget(5, 501)<<endl;
    //cout<<s.leastOpsExpressTarget(100, 100000000)<<endl;
    //cout<<s.leastOpsExpressTarget(2, 125046)<<endl;
}
