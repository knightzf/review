#include "header.h"

class Solution {
private:
    int n;
    int cand;
    int minLen;
    int minMask;
    int maxMask;
    vector<int> dict;
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size();
        cand = 0;
        maxMask = (1 << n);
        for(const auto& w : dictionary)
        {
            if(w.size() != n) continue;
            int t = 0;
            for(int i = 0; i < n; ++i)
            {
                if(target[i] != w[i]) t += 1;
                if(i != n - 1) t <<= 1;
            }
            dict.push_back(t);
            cand |= t;
        }

        minLen = INT_MAX;
        minMask = 0;
        dfs(1, 0);

        string res;
        int cnt = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(minMask & (1 << (n - 1 - i)) )
            {
                if(cnt != 0)
                {
                    res = to_string(cnt) + res;
                    cnt = 0;
                }
                res = target[i] + res;
            }
            else
            {
                ++cnt;
                if(i == 0) res = to_string(cnt) + res;
            }

        }
        return res;
    }

private:
    void dfs(int bit, int mask)
    {
        int len = abbrLen(mask);
        if(len >= minLen) return;
        bool good = true;
        for(int w : dict)
        {
            if((w & mask) == 0)
            {
                good = false;
                break;
            }
        }
        if(good)
        {
            minLen = len;
            minMask = mask;
        }
        else
        {
            for(int b = bit; b < maxMask; b <<= 1)
                if(cand & b) dfs(b << 1, mask + b);
        }
    }

    int abbrLen(int mask) {
        int cnt = 0;
        for(int i = 0, prev = 0; i < n; ++i)
        {
            if(i == 0)
            {
                prev = (mask & (1 << i));
                ++cnt;
            }
            else
            {
                int t = (mask & (1 << i));
                if(t || prev) ++cnt;
                prev = t;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<string> a{"abxdx", "xbcdx"};
    s.minAbbreviation("abcde", a);
}
