#include "header.h"

class Solution {
public:
    string smallestSubsequence(string text) {
        unordered_map<char, int> cnt;
        unordered_map<char, bool> used;
        for(char c : text) ++cnt[c];
        string res;
        for(char c : text) {
            --cnt[c];
            if(used[c]) continue;
            while(!res.empty() && res.back() > c && cnt[res.back()] > 0) {
                used[res.back()] = false;
                res.pop_back();
            }
            used[c] = true;;
            res.push_back(c);
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.smallestSubsequence("cdadabcc")<<endl;
}
