#include "header.h"

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> v;
        int t = N;
        while(t)
        {
            v.push_back(t % 10);
            t /= 10;
        }

        reverse(v.begin(), v.end());

        int n = v.size(); 
        int uniqIdx = 0;
        bool hasDup = false;
        unordered_set<int> digits;
        for(; uniqIdx < n; ++uniqIdx)
        {
            digits.insert(v[uniqIdx]);
            if(digits.size() != uniqIdx + 1)
            {
                hasDup = true;
                break;
            }
        }

        int count = hasDup ? 0 : 1;
        if(!hasDup) --uniqIdx;

        for(int i = uniqIdx; i >= 0; --i)
        {
            int choices = 0;
            for(int j = 0; j < v[i]; ++j)
            {
                if(digits.count(j) == 0)
                {
                    ++choices;
                }
            }

            if(i == 0) --choices;
            bool atDupIdx = (hasDup && i == uniqIdx);
       
            count += calcCount(choices, 10 - (int)digits.size() - (atDupIdx ? 1 : 0), n - 1 - i);
            if(!atDupIdx) digits.erase(v[i]);
        }

        for(int i = 1; i < v.size(); ++i)
        {
            count += calcCount(9, 9, i - 1);
        }

        return N - count;
    }

    int calcCount(int startChoices, int remainChoices, int numDigits)
    {
        if(startChoices == 0 || remainChoices - numDigits < 0) return 0;
        int res = startChoices;
        while(numDigits)
        {
            res *= remainChoices;
            --remainChoices;
            --numDigits;
        }
        return res;
    }
};

int main()
{
    Solution s;
    //cout<<s.numDupDigitsAtMostN(356)<<std::endl;
    //cout<<s.numDupDigitsAtMostN(2334)<<std::endl;
    cout<<s.numDupDigitsAtMostN(191)<<std::endl;
}
