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
    vector<string> findStrobogrammatic(int n) {
        if(n == 0) return vector<string>();
        if(n == 1) return vector<string>{"0", "1", "8"};

        bool isOdd = n % 2 == 1;
        int m = n / 2;

        const auto& first = getNums(1);
        const auto& r = generateHalf(isOdd ? m : m - 1, isOdd);

        vector<string> res; res.reserve(first.size() * r.size());

        for(int i = 0; i < first.size(); ++i)
        {
            for(int j = 0; j < r.size(); ++j)
            {
                string temp = first[i] + r[j];
                int sz = isOdd ? temp.size() - 2 : temp.size() - 1;
                for(int k = sz; k >= 0; --k)
                {
                    temp += getChar(temp[k]);
                }

                res.push_back(temp);
            }
        }

        return res;
    }

    vector<string> generateHalf(int n, bool isOdd)
    {
        if(n == 0) return vector<string>{""};

        if(n == 1)
        {
            if(isOdd)
            {
                return getNums(2);
            }
            else
            {
                return getNums();
            }
        }

        const auto& first = getNums();
        const auto& r = generateHalf(n - 1, isOdd);

        vector<string> res;

        for(int i = 0; i < first.size(); ++i)
        {
            for(int j = 0; j < r.size(); ++j)
            {
                res.push_back(first[i] + r[j]);
            }
        }

        return res;
    }

    vector<string> getNums(int mode = 0)
    {
        if(mode == 0)
        {
            return {"0","1","8","6","9"};
        }
        else if(mode == 1)
        {
            return {"1","8","6","9"};
        }
        else
        {
            return {"0","1","8"};
        }
    }

    char getChar(char c)
    {
        static std::unordered_map<int, char> m{
            {'0', '0'},
            {'1', '1'},
            {'8', '8'},
            {'6', '9'},
            {'9', '6'}
        };

        return m[c];
    }
};


int main() {
    Solution s;
    const auto& r = s.findStrobogrammatic(4);
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
