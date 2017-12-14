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
    vector<string> restoreIpAddresses(string s)
    {
        return impl(s, 4);
    }

    vector<string> impl(const std::string& s, int secLeft)
    {
        vector<string> res;

        if(secLeft == 1)
        {
            if(validIp(s, std::stoi(s)))
            {
                res.push_back(s);
            }
            return res;
        }

        int n = s.size();

        for(int i = 1; i <= 3; ++i)
        {
            if(i > n) break;

            const std::string& ip = s.substr(0, i);
            if(validIp(ip, std::stoi(ip)) && validLen(n - i, secLeft - 1))
            {
                const auto& r = impl(s.substr(i), secLeft - 1);
                for(const auto& item : r)
                {
                    res.push_back(ip + '.' + item);
                }
            }
        }

        return res;
    }

private:
    bool validIp(const std::string& ips, int ip)
    {
        return ((ips.size() > 1 && ips[0] != '0' || ips.size() == 1) && ip >= 0 && ip <= 255);
    }

    bool validLen(int len, int count)
    {
        return len <= count * 3 && len >= count;
    }
};

int main()
{
    Solution s;
    //const auto& a = s.restoreIpAddresses("25525511135");
    const auto& a = s.restoreIpAddresses("010010");
    for(const auto & i : a)
    {
        std::cout<<i<<std::endl;
    }
}
