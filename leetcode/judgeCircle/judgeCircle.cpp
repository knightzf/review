#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        
        for(size_t i = 0, sz = moves.size(); i < sz; ++i)
        {
            switch(moves[i])
            {
                case 'U':
                    ++y;
                    break;
                case 'D':
                    --y;
                    break;
                case 'L': 
                    --x;
                    break;
                case 'R': 
                    ++x; 
                    break;
                default: break;
            }
        }
        
        if(x == 0 && y ==0)
            return true;
            
        return false;
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.judgeCircle("LL")<<std::endl;
	return 0;
}