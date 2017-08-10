#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLen = 0;
        std::map<char, size_t> charMap;
        
        for(size_t i = 0; i < s.size();)
        {
            auto iter = charMap.find(s[i]);
            if(iter != charMap.end())
            {
                maxLen = charMap.size() > maxLen ? charMap.size() : maxLen;
                charMap.clear();
                i = iter->second + 1;
            }
            else
            {
                charMap.insert(std::make_pair(s[i], i));
                ++i;
            }
        }
        
        maxLen = charMap.size() > maxLen ? charMap.size() : maxLen;
        
        return maxLen;
    }
};

int main()
{
	return 0;
}