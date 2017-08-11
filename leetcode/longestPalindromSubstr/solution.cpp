#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if(s.size() == 1 || s.empty())
            return s;
            
        for(size_t i = 0, sz = s.size(); i < sz - 1; ++i)
        {
            checkString(s, i, i);
            checkString(s, i, i+1);
        }
        
        return paliStr;
    }
    
    void checkString(const std::string& s, size_t m, size_t n)
    {
        size_t lastIdx = s.size() - 1;
        
        while(true)
        {       
            if(s[m] == s[n])
            {
                if(m == 0 || n == lastIdx)
                    break;
                --m;
                ++n;
            }
            else
            {
                ++m;
                --n;
                break;
            }            
        }
        
        if(n - m + 1 > maxLen)
        {
            maxLen = n - m + 1;
            paliStr = s.substr(m, maxLen);
        }
    }
    
private:
    std::string paliStr;
    size_t maxLen = 0;
};

int main()
{
    Solution sol;
    std::cout<<sol.longestPalindrome("bananas")<<std::endl;
	return 0;
}