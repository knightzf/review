#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(s.empty() || s.size() == 1)
            return s;
            
        size_t lastIdx = s.size() - 1;
        size_t zigLen = numRows;
        size_t zagLen = numRows - 2;
        
        std::stringstream ss;
        
        for(size_t i = 0; i < numRows; ++i)
        {
            for(size_t j = 0; true; j += 1)
            {
                size_t idx = j * (zigLen + zagLen) + i;
                if(idx > lastIdx)
                    break;
                else
                    ss << s[idx];
                    
                if(i != 0 && i != numRows - 1)
                {
                    idx = idx + zigLen + zagLen - 2 * i;
                    if(idx > lastIdx)
                        break;
                    else
                        ss << s[idx];
                }
            }
        }
        
        return ss.str();
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.convert("PAYPALISHIRING", 3)<<std::endl;
	return 0;
}