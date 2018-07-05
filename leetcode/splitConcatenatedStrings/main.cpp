#include "header.h"

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        char maxChar = 0;
        int n = strs.size();
        string total;
        for(int i = 0; i < n; ++i)
        {
            auto t = strs[i];
            reverse(t.begin(), t.end());
            if(t > strs[i])
            {
                total += t;
            }
            else
            {
                total += strs[i];
            }

            for(char c : strs[i])
            {
                maxChar = max(maxChar, c);
            }
        }

        string res;
        int startIdx = 0;
        for(int i = 0; i < n; ++i)
        {
            int endIdx = startIdx + strs[i].size();
            if(strs[i].find(maxChar) != string::npos)
            {
                reverse(total.begin() + startIdx, total.begin() + endIdx);
                for(int i = startIdx; i < endIdx; ++i)
                {
                    if(total[i] == maxChar)
                    {
                        res = max(res, total.substr(i) + total.substr(0, i));
                    }
                }
                reverse(total.begin() + startIdx, total.begin() + endIdx);
                for(int i = startIdx; i < endIdx; ++i)
                {
                    if(total[i] == maxChar)
                    {
                        res = max(res, total.substr(i) + total.substr(0, i));
                    }
                }
            }
            startIdx = endIdx;
        }

        return res;
    }
};

int main()
{
    Solution s;
    //vector<string> a{"ab","xy","cd","aaa","bab"};
    vector<string> a{"zzzxxzzzzzzzzzaewfawfbc","bcd","acef","xyz","az","ba","a","z","abc","bcd","acef","xyz","az","ba","a","z","abawefeac","bceawfeawfd","acef","xyz","az","ba","a","z","abc","bcd","acef","xyz","az","baewfeawfa","awefawfa","zweafewaf","abc","bcd","acef","xyz","az","ba","a","z","abc","bcdaewf","acef","xyz","az","ba","a","z","abc","bcd","acef","xyz","az","ba","a","z","abeawfawfac","bcd","acef","efawfxyz","aeawfafz","baewfefa","a","zawefawfawf","aewfawfbc","bcd","acef","xyz","az","ba","a","z","abc","bcd","acef","xyz","az","ba","a","z","abawefeac","bceawfeawfd","acef","xyz","az","ba","a","z","abc","bcd","acef","xyz","az","baewfeawfa","awefawfa","zweafewaf","abc","bcd","acef","xyz","az","ba","a","z","abc","bcdaewf","acef","xyz","az","ba","a","z","abc","bcd","acef","xyz","az","ba","a","z","abeawfawfac","bcd","acef","efawfxyz","aeawfafz","baewfefa","a","zawefawfawf"};
    s.splitLoopedString(a);
}
