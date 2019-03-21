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
        unordered_set<int> digits;
        for(; uniqIdx < n; ++uniqIdx)
        {
            digits.insert(v[uniqIdx]);
            if(digits.size() != uniqIdx + 1)
            {
                --uniqIdx;
                break;
            }
        }

        int count = 0;
        if(uniqIdx != n)
        {
            int choices = 0;
            for(int i = 0; i < v[uniqIdx + 1]; ++i)
            {
                if(digits.count(i) == 0)
                {
                    ++choices;
                }
            }
            count += calcCount(choices, 10 - (int)digits.size() - 1, n - 2 - uniqIdx);
        }
        else
        {
            --uniqIdx;
            ++count;
        }

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
       
            count += calcCount(choices, 10 - (int)digits.size(), n - 1 - i);
            digits.erase(v[i]);
        }

        for(int i = 1; i < v.size(); ++i)
        {
            count += calcCount(9, 9, i - 1);
        }

        return N - count;
    }

    int calcCount(int startChoices, int remainChoices, int numDigits)
    {
        if(startChoices == 0 || remainChoices - numDigits <= 0) return 0;
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
