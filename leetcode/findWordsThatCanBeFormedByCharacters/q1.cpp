#include "header.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0);
        for(char c : chars) ++cnt[c - 'a'];
        int res = 0;
        for(const auto& w : words) {
            vector<int> t(26, 0);
            for(char c : w) ++t[c - 'a'];
            bool good = true;
            for(int i = 0; i < 26; ++i) {
                if(t[i] > cnt[i]) {
                    good = false;
                    break;
                }
            }
            if(good) res += w.size();
        }
        return res;
    }
};

int main()
{
    Solution s;
}
