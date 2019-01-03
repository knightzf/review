#include "header.h"

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0, k, pos2, neg2, cur;
        for (k = 0; target > 0; ++k, target /= x) {
            cur = target % x;
            if (k > 0) {
                pos2 = min(cur * k + pos, (cur + 1) * k + neg);
                neg2 = min((x - cur) * k + pos, (x - cur - 1) * k + neg);
                pos = pos2, neg = neg2;
            } else {
                pos = cur * 2;
                neg = (x - cur) * 2;
            }
            cout<<target<<" "<<cur<<" "<<pos<<" "<<neg<<endl; 
        }
        return min(pos, k + neg) - 1;
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
