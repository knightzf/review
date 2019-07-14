#include "header.h"

class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> cnt(26, 0);
        vector<int> nextIdx(26, 0);
        for(char c : s) ++cnt[c - 'a'];
        string res;
        auto next = [&](int idx) {
            int res = -1;
            int count = INT_MIN;
            for(int i = 0; i < 26; ++i) {
                if(cnt[i] > 0 && nextIdx[i] <= idx) {
                    if(cnt[i] > count) {
                        count = cnt[i];
                        res = i;
                    }
                }
            }
            return res;
        };
        for(int i = 0, n = s.size(); i < n; ++i) {
            int nextChar = next(i);
            if(nextChar == -1) return "";
            res += 'a' + nextChar;
            --cnt[nextChar];
            nextIdx[nextChar] += k;
        }
        return res;
    }
};

int main()
{
    Solution s;
    //cout<<s.rearrangeString("aaadbbcc", 2)<<endl;
    //cout<<s.rearrangeString("aabbcc", 2)<<endl;
    //cout<<s.rearrangeString("abcdabcdabdeac", 4)<<endl;
    cout<<s.rearrangeString("aaabc", 2)<<endl;
}