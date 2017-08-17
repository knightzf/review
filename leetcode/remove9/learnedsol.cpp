#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>

using namespace std;

class Solution {
public:    
    int newInteger(int n) {
        int base = 1;
        
        int res = n % 9;
        int mul = n/9;
        
        int result = 0;
        
        while(true)
        {
            result += res * base;
            
            if(mul == 0)
                break;
                
            n = mul;
            res = n % 9;
            mul = n / 9;
            base *= 10;
        }
        
        return result;
    }
};

int main()
{
    Solution sol;    
    std::cout<<"count "<<sol.newInteger(1568)<<std::endl;
	return 0;
}