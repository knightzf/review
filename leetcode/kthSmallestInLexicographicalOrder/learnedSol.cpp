#include "header.h"

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k - 1;
        while(k > 0)
        {
            int steps = calcSteps(n, curr, curr + 1);
            if(steps <= k)
            {
                curr += 1;
                k -= steps;
            }
            else
            {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

    int calcSteps(long n, long n1, long n2)
    {
        int steps = 0;
        while(n1 <= n)
        {
            steps += min(n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};

int main()
{
    Solution s;
    //cout<<s.findKthNumber(13, 2)<<endl;
    cout<<s.findKthNumber(100, 10)<<endl;
}
