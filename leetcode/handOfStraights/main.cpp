#include "header.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(W == 1) return true;
        int n = hand.size();
        if(n % W != 0) return false;

        sort(hand.begin(), hand.end());
        for(int i = 0; i < n; ++i)
        {
            if(hand[i] != -1)
            {
                int t = hand[i];
                int j = i + 1;
                while(j < n)
                {
                    if(hand[j] == t + 1)
                    {
                        hand[j] = -1;
                        ++t;
                        if(t == hand[i] + W - 1) break;
                    }
                    ++j;
                }
                if(t != hand[i] + W - 1) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,3,6,2,3,4,7,8};
    cout<<s.isNStraightHand(a, 3)<<endl;
}
