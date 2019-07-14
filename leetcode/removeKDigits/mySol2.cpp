#include "header.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        deque<char> s;
        for(int i = 0, n = num.size(); i < n; ++i) {
            while(!s.empty() && num[i] < s.back() && k) {
                s.pop_back();
                --k;
            }
            s.push_back(num[i]);
        }
        while(k) {
            s.pop_back();
            --k;
        }
        while(s.size() > 1 && s.front() == '0') s.pop_front();
        string res;
        while(!s.empty()) {
            res += s.front();
            s.pop_front();
        }
        return res;
    }
};

int main()
{
    Solution s;
}