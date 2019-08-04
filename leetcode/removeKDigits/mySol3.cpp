#include "header.h"

class Solution {
public:
    string removeKdigits(string num, int k, bool allowzero = true, bool skipzero = true) {
        int n = num.size();
        if(n <= k) return allowzero ? "0" : "";
        if(k == 0) return num;

        char c = num[0]; int idx = 0;
        for(int i = 0; i <= k; ++i) {
            if(skipzero && num[i] == '0') {
                int j = i;
                while(j < n && num[j] == '0') ++j;
                return removeKdigits(num.substr(j), k - i, true, true);
            } else {
                if(num[i] < c) {
                    c = num[i];
                    idx = i;
                }
            }
        }
        return num[idx] + removeKdigits(num.substr(idx + 1), k - idx, false, false);
    }
};

int main()
{
    Solution s;
}