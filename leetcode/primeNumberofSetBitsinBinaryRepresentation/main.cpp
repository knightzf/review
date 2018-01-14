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
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for(int i = L; i <= R; ++i)
        {
            int numDigits = std::ceil(log(i)/log(2));
            if((i & (i - 1)) == 0) numDigits += 1;

            int t = 1;
            int count = 0;
            for(int j = 0; j < numDigits; ++j)
            {
                if(j > 0) t <<= 1;

                if(i & t)
                {
                    ++count;
                }
            }

            if(isPrime(count))
            {
                //std::cout<<i<<" "<<count<<std::endl;
                ++res;
            }
        }

        return res;
    }

    bool isPrime(int a)
    {
        static std::unordered_set<int> primeCache{2};
        static std::unordered_set<int> nonprimeCache{1};

        if(primeCache.find(a) != primeCache.end())
        {
            return true;
        }

        if(nonprimeCache.find(a) != nonprimeCache.end())
        {
            return false;
        }

        for(int i = 2; i <= a / 2; ++i)
        {
            if(a % i == 0)
            {
                nonprimeCache.insert(a);
                return false;
            }
        }

        primeCache.insert(a);
        return true;
    }
};

int main() {
    Solution s;
    //std::cout<<s.countPrimeSetBits(6, 10)<<std::endl;
    //std::cout<<s.countPrimeSetBits(10, 15)<<std::endl;
    std::cout<<s.countPrimeSetBits(244, 269)<<std::endl;
}
