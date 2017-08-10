#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLen = 0;
        std::set<char> charSet;
        
        size_t startIdx = 0;
        
        for(size_t i = 0; i < s.size(); ++i)
        {
            auto iter = charSet.find(s[i]);
            
            if(iter == charSet.end())
            {
                charSet.insert(s[i]);
            }
            else
            {
                while(startIdx < i)
                {
                    bool found = s[startIdx] != s[i];
                    
                    if(found)
                    {
                        charSet.erase(charSet.find(s[startIdx]));
                    }
                    
                    ++startIdx;
                    
                    if(!found)
                    {
                        break;
                    }
                }
            }
            
            int temp = i - startIdx + 1;
            maxLen = temp > maxLen ? temp : maxLen;
        }
        
        return maxLen;
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.lengthOfLongestSubstring("dvdf")<<std::endl;
	return 0;
}