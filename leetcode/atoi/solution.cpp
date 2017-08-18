#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {        
        double result = 0;
        int sign = 1;
        
        size_t idx = 0;
        while(idx < str.size())
        {
            if(str[idx] == ' ')
            {
                ++idx;
                continue;
            }
                
            if(str[idx] == '+' || str[idx] == '-' )
            {
                sign = str[idx] == '+' ? 1 : -1;
                ++idx;
                break;
            }
            
            if(isdigit(str[idx]))
                break;
            
            if(!isdigit(str[idx]))
                return 0;
                
            ++idx;
        }
        
        for(size_t i = idx; i < str.size(); ++i)
        {
            if(!isdigit(str[i]))
                break;
                
            result = result * 10 + str[i] - '0';
        }
        
        result *= sign;
        
        if(result > INT_MAX)
            result = INT_MAX;
        
        if(result < INT_MIN)
            result = INT_MIN;
        
        return result;
    }
};

int main()
{
    Solution sol;    
    std::cout<<sol.myAtoi(" b11228552307")<<std::endl;
	return 0;
}