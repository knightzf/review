#include "header.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 0) return true;
        bool firstCap = isupper(word[0]);
        if(firstCap)
        {
            bool allCap = true;
            bool hasCap = false;
            for(int i = 1; i < n; ++i)
            {
                if(islower(word[i])) allCap = false;
                if(isupper(word[i])) hasCap = true;
            }

            if(!allCap && hasCap) return false;
        }
        else
        {
            for(int i = 1; i < n; ++i)
                if(isupper(word[i])) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
}
