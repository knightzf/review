#include "header.h"

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        return max(0, helper(high) - helper(to_string(stoi(low) - 1)));
    }

    int getCount(int len) {
        static unordered_map<int, int> m{{1, 3}};
        if(!m.count(len)) {
            int res = 4;
            for(int i = 1; i <= (len - 1) / 2; ++i) res *= 5;
            if(len & 1) res = res / 5 * 3;
            m[len] = res;
        }
        return m[len];
    }

    int helper(const string& s) {
        static unordered_map<char, char> m{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};   
        if(s[0] == '-') return 0;
        int res = 0, len = s.size();
        if(len == 1) {
            if(s[0] >= '8') return 3;
            if(s[0] >= '1') return 2;
            return 1;
        }
        for(int i = 1; i < len; ++i) {
            res += getCount(i);
        }
        //cout<<res<<endl;
        auto f = [&](int idx) {
            int t = 0;
            if(s[idx] > '8') t = 3 + (idx ? 1 : 0);
            else if(s[idx] > '6') t = 2 + (idx ? 1 : 0);
            else if(s[idx] > '1') t = 1 + (idx ? 1 : 0);
            else if(s[idx] > '0') t = (idx ? 1 : 0);
            for(int i = idx + 1; i <= (len - 1) / 2; ++i) t *= 5;
            if((len & 1) && idx != (len - 1) / 2) t = t / 5 * 3;
            return t;
        };
        for(int i = 0; i < len; ++i) {
            if(i > (len - 1) / 2 && m.count(s[(len - 1) / 2])) {
                string t = s;
                for(int j = 0, k = len - 1; j <= (len - 1) / 2; ++j, k -= 2) {
                    t[j + k] = m[t[j]];
                }
                //cout<<t<<endl;
                if(t <= s) ++res;
                break;
            }
            if(i == 0 || m.count(s[i - 1])) res += f(i);
            else break;
        }
        
        return res;
    }
};

int main()
{
    Solution s;
}