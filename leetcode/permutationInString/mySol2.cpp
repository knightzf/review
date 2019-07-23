#include "header.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int cnt = 0, m = s1.size(), n = s2.size();
        vector<int> v(26, 0);
        for(char c : s1) {
            ++v[c - 'a'];
            if(v[c - 'a'] == 1) ++cnt;
        }
        for(int i = 0; i < n; ++i) {
            --v[s2[i] - 'a'];
            if(v[s2[i] - 'a'] == 0) --cnt;
            if(v[s2[i] - 'a'] == -1) ++cnt;
            if(i >= m) {
                int idx = s2[i - m] - 'a';
                ++v[idx];
                if(v[idx] == 0) --cnt;
                if(v[idx] == 1) ++cnt;
            }
            if(cnt == 0) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
}