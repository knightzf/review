#include "header.h"

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        static int m = (2 << 6);
        for(int i = 0; i < n; )
        {
            stack<bool> s;
            int t = data[i];
            for(int j = 0; j < 8; ++j)
            {
                s.push((t >> j) & 1);
            }

            if(s.top() == false) ++i;
            else
            {
                int cntOfOne = 0;
                while(!s.empty() && s.top())
                {
                    ++cntOfOne;
                    s.pop();
                }
                if(cntOfOne == 1 || cntOfOne > 4 || i + cntOfOne > n) return false;
                for(int j = 1; j < cntOfOne; ++j)
                {
                    if((data[i + j] & m) != m) return false;
                }
                i += cntOfOne;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> a{235, 140, 4};
    std::cout<<s.validUtf8(a)<<std::endl;
}
