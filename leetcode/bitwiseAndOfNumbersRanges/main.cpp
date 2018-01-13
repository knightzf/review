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
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        if(m == 0) return 0;

        int tm = std::ceil(log(m)/log(2));
        if((m & (m - 1)) == 0) tm += 1;

        //std::cout<<tm<<std::endl;
        if(n > std::pow(2, tm) - 1)
        {
            return 0;
        }

        int res = 0;

        for(int i = tm; i > 0; --i)
        {
            int t = std::pow(2, i - 1);
            if(m >= t && n >= t)
            {
                res += t;
                m -= t;
                n -= t;
            }
            else
            {
                //std::cout<<m<<" "<<n<<std::endl;
                res += rangeBitwiseAnd(m, n);
                break;
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    //std::cout<<s.rangeBitwiseAnd(1, 2)<<std::endl;
    //std::cout<<s.rangeBitwiseAnd(1, 3)<<std::endl;
    //std::cout<<s.rangeBitwiseAnd(5, 7)<<std::endl;
    std::cout<<s.rangeBitwiseAnd(2, 3)<<std::endl;
}
