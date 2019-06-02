#include "header.h"

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() == t.size()) {
            int cnt = 0;
            for(int i = 0, n = s.size(); i < n; ++i) {
                if(s[i] != t[i]) {
                    ++cnt;
                }
            }
            return cnt == 1;
        }
        if(s.size() > t.size()) {
            swap(s, t);
        }
        if(t.size() - s.size() != 1) return false;
        for(int i = 0, j = 0, n = s.size(), cnt = 0; i < n && j < n + 1;) {
            if(s[i] == t[j]) {
                ++i; ++j;
            } else {
                ++j; ++cnt;
                if(cnt > 1) return false;
            }
        }
        return true;
    }
};

int main()
{
    //Solution s;    
}