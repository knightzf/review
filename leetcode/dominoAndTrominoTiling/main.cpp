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
    int numTilings(int N) {
        return impl(N, false) % (1000000007);
    }

    long impl(int N, bool mode)
    {
        static std::unordered_map<int, long> m1;
        static std::unordered_map<int, long> m2;
        if(m1.empty())
        {
            m1[0] = 1; m1[1] = 1;
            m2[0] = 1; m2[1] = 1;
        }

        if(mode == false)
        {
            if(m1.find(N) != m1.end())
            {
                return m1[N];
            }
            else
            {
                long t = impl(N - 1, false) % (1000000007) + impl(N - 2, false) % (1000000007) +
                    (N > 2 ? 2 * impl(N - 2, true) % (1000000007) : 0);
                m1[N] = t;
                return t;
            }
        }
        else
        {
            if(m2.find(N) != m2.end())
            {
                return m2[N];
            }
            else
            {
                long t = impl(N - 1, false) % (1000000007) + (N > 1 ? impl(N - 1, true) % (1000000007) : 0);
                m2[N] = t;
                return t;
            }
        }
    }
};

int main() {
    Solution s;
    //std::cout<<s.numTilings(2)<<std::endl;
    //std::cout<<s.numTilings(3)<<std::endl;
    std::cout<<s.numTilings(30)<<std::endl;
    std::cout<<s.numTilings(60)<<std::endl;
}
