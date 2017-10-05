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

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k)
    {
        std::stringstream ss;

        std::vector<int> v;
        for(int i = 1; i <=n; ++i)
        {
            v.push_back(i);
        }

        int t = n;

        while(true)
        {
            int fac = factorial(t - 1);
            int d = std::ceil(k / (double)fac);

            ss<<v[d - 1];
            v.erase(v.begin() + d - 1);

            --t;
            k = k % fac;

            if(k == 0)
            {
                for(auto i = v.rbegin(); i != v.rend(); ++i)
                {
                    ss << *i;
                }

                break;
            }
        }

        return ss.str();
    }

private:
    int factorial(int x)
    {
        if(x == 0)
            return 1;

        return (x == 1 ? x : x * factorial(x - 1));
    }
};


int main()
{
    Solution sol;
    std::cout<<sol.getPermutation(1, 1)<<std::endl;
    std::cout<<sol.getPermutation(2, 1)<<std::endl;
    std::cout<<sol.getPermutation(2, 2)<<std::endl;
    std::cout<<sol.getPermutation(3, 2)<<std::endl;
    std::cout<<sol.getPermutation(3, 4)<<std::endl;
    return 0;
}
