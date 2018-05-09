#include "header.h"

class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int startIdx = -1;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == ' ')
            {
                startIdx = -1;
            }
            else
            {
                if(startIdx == -1)
                {
                    ++res;
                    startIdx = i;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.countSegments("Hello, my name is John")<<std::endl;
}
