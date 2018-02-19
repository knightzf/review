#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        std::map<long, int> m;
        m.emplace(1, -1);

        int sz = primes.size();
        for(int i = 0; i < sz; ++i)
        {
            m.emplace(primes[i], i);
        }

        while(n != 0)
        {
            --n;
            const auto& first = *m.begin();
            if(n == 0) return first.first;
            else
            {
                if(first.second != -1)
                {
                    for(int i = first.second; i < sz; ++i)
                    {
                        //std::cout<<first.first * primes[i]<<" "<<first.second<<std::endl;
                        m.emplace(first.first * primes[i], first.second);
                    }
                }

                m.erase(m.begin());
            }
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a{2, 7, 13, 19};
    std::cout<<s.nthSuperUglyNumber(12, a)<<std::endl;
}
