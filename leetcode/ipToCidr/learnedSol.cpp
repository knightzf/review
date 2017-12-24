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

using namespace std;

class Solution {
public:
    using Long = long long;
    vector<string> ipToCIDR(string ip, int range)
    {
        vector<string> res;

        Long ipNum = toNum(ip);

        while(range > 0)
        {
            int numZeros = numOfZeros(ipNum);
            while(std::pow(2, numZeros) > range)
            {
                --numZeros;
            }

            res.push_back(toString(ipNum, numZeros));

            ipNum += std::pow(2, numZeros);

            range -= std::pow(2, numZeros);
        }

        return res;
    }

    std::string toString(Long ipNum, int numZeros)
    {
        int a, b, c, d;

        a = ipNum % 256;
        ipNum /= 256;

        b = ipNum % 256;
        ipNum /= 256;

        c = ipNum % 256;
        ipNum /= 256;

        d = ipNum % 256;
        ipNum /= 256;

        std::stringstream ss;
        ss<<d<<"."<<c<<"."<<b<<"."<<a<< "/"<<(32 - numZeros);

        //std::cout<<ss.str()<<std::endl;
        return ss.str();
    }

    int numOfZeros(Long ipNum)
    {
        if (ipNum == 0) return 32;

        int c = 0;
        while(ipNum % 2 == 0)
        {
            ipNum = ipNum / 2;
            ++c;
        }

        return c;
    }

    Long toNum(string ip)
    {
        int s1, s2, s3, s4;
        sscanf (ip.c_str(),"%d.%d.%d.%d", &s1, &s2, &s3, &s4);
        return s4 + s3 *256 + s2 * 256 * 256 + (Long)s1 * 256 * 256 * 256;
    }
};

int main()
{
    Solution s;
    s.ipToCIDR("0.171.255.5", 422);
}
