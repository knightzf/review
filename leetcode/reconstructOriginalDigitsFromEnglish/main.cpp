#include "header.h"

class Solution {
public:
    string originalDigits(string s) {
        vector<int> cnt(26, 0);
        for(char c : s)
        {
            ++cnt[c - 'a'];
        }

        vector<int> digitCnt(10, 0);
        while(cnt['z' - 'a'])
        {
            ++digitCnt[0];
            --cnt['z' - 'a'];
            --cnt['e' - 'a'];
            --cnt['r' - 'a'];
            --cnt['o' - 'a'];
        }
        while(cnt['w' - 'a'])
        {
            ++digitCnt[2];
            --cnt['t' - 'a'];
            --cnt['w' - 'a'];
            --cnt['o' - 'a'];
        }
        while(cnt['x' - 'a'])
        {
            ++digitCnt[6];
            --cnt['s' - 'a'];
            --cnt['i' - 'a'];
            --cnt['x' - 'a'];
        }
        while(cnt['u' - 'a'])
        {
            ++digitCnt[4];
            --cnt['f' - 'a'];
            --cnt['o' - 'a'];
            --cnt['u' - 'a'];
            --cnt['r' - 'a'];
        }
        while(cnt['g' - 'a'])
        {
            ++digitCnt[8];
            --cnt['e' - 'a'];
            --cnt['i' - 'a'];
            --cnt['g' - 'a'];
            --cnt['h' - 'a'];
            --cnt['t' - 'a'];
        }
        while(cnt['o' - 'a'])
        {
            ++digitCnt[1];
            --cnt['o' - 'a'];
            --cnt['n' - 'a'];
            --cnt['e' - 'a'];
        }
        while(cnt['t' - 'a'])
        {
            ++digitCnt[3];
            --cnt['t' - 'a'];
            --cnt['h' - 'a'];
            --cnt['r' - 'a'];
            --cnt['e' - 'a'];
            --cnt['e' - 'a'];
        }
        while(cnt['f' - 'a'])
        {
            ++digitCnt[5];
            --cnt['f' - 'a'];
            --cnt['i' - 'a'];
            --cnt['v' - 'a'];
            --cnt['e' - 'a'];
        }
        while(cnt['s' - 'a'])
        {
            ++digitCnt[7];
            --cnt['s' - 'a'];
            --cnt['e' - 'a'];
            --cnt['v' - 'a'];
            --cnt['e' - 'a'];
            --cnt['n' - 'a'];
        }
        while(cnt['i' - 'a'])
        {
            ++digitCnt[9];
            --cnt['n' - 'a'];
            --cnt['i' - 'a'];
            --cnt['n' - 'a'];
            --cnt['e' - 'a'];
        }

        string res;
        for(int i = 0; i < 10; ++i)
        {
            while(digitCnt[i])
            {
                res += '0' + i;
                --digitCnt[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.originalDigits("owoztneoer")<<std::endl;
}
