#include "header.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n < 2) return n;
        char c = chars[0];
        int j = 1;
        for(int i = 1, cnt = 1; i <= n; ++i) {
            if(i == n || chars[i] != c) {
                if(cnt > 1) {
                    string t = to_string(cnt);
                    for(int k = 0; k < t.size(); ++k) chars[j + k] = t[k];
                    j += t.size();
                }
                cnt = 1;
                if(i < n) {
                    c = chars[i];
                    chars[j] = c;
                    ++j;
                }
            } else ++cnt;
        }
        return j;
    }
};

int main()
{
    //Solution s;
}