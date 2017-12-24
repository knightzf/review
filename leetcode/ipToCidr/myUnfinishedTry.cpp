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
    vector<string> ipToCIDR(string ip, int range) {
        std::vector<int> ipV;
        int idx = ip.find('.');
        ipV.push_back(std::stoi(ip.substr(0, idx)));
        ip = ip.substr(idx + 1);

        idx = ip.find('.');
        ipV.push_back(std::stoi(ip.substr(0, idx)));
        ip = ip.substr(idx + 1);

        idx = ip.find('.');
        ipV.push_back(std::stoi(ip.substr(0, idx)));
        ip = ip.substr(idx + 1);

        ipV.push_back(std::stoi(ip));

        /*for(auto i : ipV)
        {
            std::cout<<i<<std::endl;
        }*/

        vector<string> res;

        while(range)
        {
            int numZeros = numOfZeros(ipV);
            if(std::pow(2, numZeros) < range)
            {
                range -= std::pow(2, numZeros);
                std::cout<<toString(ipV, numZeros)<<std::endl;
                res.push_back(toString(ipV, numZeros));

                increase(ipV, std::pow(2, numZeros));
            }
            else
            {

            }
            break;
        }

        return res;
    }

    void increase(std::vector<int>& ipV)
    {

    }

    std::string toString(std::vector<int>& ipV, int numZeros)
    {
        std::stringstream s;
        s<<ipV[0]<<'.'<<ipV[1]<<'.'<<ipV[2]<<'.'<<ipV[3]<<'/'<<(32 - numZeros);
        return s.str();
    }

    int numOfZeros(std::vector<int>& ipV)
    {
        int count = 0;

        for(int i = 3; i >= 0; --i)
        {
            int n = ipV[i];
            int c = 0;

            if(n == 0)
            {
                c = 8;
            }
            else
            {
                while(n % 2 == 0)
                {
                    ++c;
                    n = n / 2;
                }
            }

            count += c;

            if(c != 8)
            {
                break;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    s.ipToCIDR("255.0.0.7", 10);
}
