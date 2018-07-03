#include "header.h"

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int absentCnt = 0;
        int lateCnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'A')
                ++absentCnt;
            else if(s[i] == 'L')
            {
                if(i != 0 && s[i - 1] == 'L')
                {
                    ++lateCnt;
                }
                else
                {
                    lateCnt = 1;
                }
            }
            else
            {
                lateCnt = 0;
            }

            if(absentCnt > 1 || lateCnt > 2) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
}
