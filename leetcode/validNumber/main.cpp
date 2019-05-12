#include "header.h"

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int startIdx = 0, endIdx = n;
        while(startIdx < n && s[startIdx] == ' ') ++startIdx;
        while(endIdx > 0 && s[endIdx - 1] == ' ') --endIdx;
        if(startIdx >= endIdx) return false;

        bool hasNum = false, hasSign = false, hasDot = false, hasExp = false;
        unordered_set<char> ss{'+', '-', 'e', '.'};
        for(int i = startIdx; i < endIdx; ++i)
        {
            if(!isdigit(s[i]))
            {
                if(!ss.count(s[i])) return false;
                if(s[i] == 'e') {
                    if(hasNum && !hasExp) {
                        hasExp = true; 
                        hasNum = false;
                        hasSign = false;
                        hasDot = true;
                        continue;
                    }
                    return false;
                }
                if(s[i] == '.') {
                    if(hasDot) return false;
                    hasDot = true;
                    continue;               
                }
                if((i == startIdx || s[i - 1] == 'e') && !hasSign) {
                    hasSign = true;
                }
                else return false;
            }
            else {
                if(!hasNum) hasNum = true;
            }
        }
        return hasNum;
    }
};


int main()
{
    Solution s;
    cout<<s.isNumber(" 0.1 ")<<endl;
}