#include "header.h"

class Solution {
public:
    int uniqueLetterString(string S) {
        if(S.empty()) return 0;
        std::for_each(S.begin(), S.end(), [](char& c){
                      c = std::tolower(c);});

        vector<int> v(26, 0);
        int n = S.size();
        int res = 0;
        int fullStrVal = 0;
        for(int i = 0; i < n; ++i)
        {
            ++v[S[i] - 'a'];
            if(v[S[i] - 'a'] == 1)
                ++fullStrVal;
            else if(v[S[i] - 'a'] == 2)
                --fullStrVal;

            res += fullStrVal;
            res %= 1000000007;
        }

        for(int i = 1; i < n; ++i)
        {
            --v[S[i - 1] - 'a'];
            if(v[S[i - 1] - 'a'] == 1)
                fullStrVal += 1;
            else if(v[S[i - 1] - 'a'] == 0)
                fullStrVal -= 1;

            int t = impl(S, i, v, fullStrVal)% 1000000007;
            //std::cout<<fullStrVal<<" "<<t<<std::endl;
            res += t;
            res %= 1000000007;
        }
        return res;
    }

    int impl(const string& s, int startIdx, vector<int> v, int lastValue)
    {
        int res = lastValue;
        int t = lastValue;
        for(int i = s.size() - 1; i > startIdx; --i)
        {
            --v[s[i] - 'a'];
            if(v[s[i] - 'a'] == 1)
                ++t;
            else if(v[s[i] - 'a'] == 0)
                --t;
            //std::cout<<startIdx<<" "<<t<<" aa"<<std::endl;
            res += t;
            res %= 1000000007;
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.uniqueLetterString("AAA")<<std::endl;
}
