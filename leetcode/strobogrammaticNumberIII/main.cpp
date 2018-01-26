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
    int strobogrammaticInRange(string low, string high) {
        int lowLen = low.size();
        int highLen = high.size();

        if(lowLen > highLen) return 0;

        int res = 0;

        if(lowLen == highLen)
        {
            const auto& rlow = getNums(lowLen, lowLen);
            for(const auto& i : rlow)
            {
                if(i >= low && i <= high) ++res;
            }
        }
        else
        {
            for(int i = lowLen + 1; i < highLen; ++i)
            {
                res += getCount(i);
            }

            const auto& rlow = getNums(lowLen, lowLen);
            for(const auto& i : rlow)
            {
                if(i >= low) ++res;
            }
            const auto& rhigh = getNums(highLen, highLen);
            for(const auto& i : rhigh)
            {
                if(i <= high) ++res;
            }
        }

        return res;
    }

private:
    int getCount(int n)
    {
        bool isOdd = n % 2 == 1;
        int m = isOdd ? n / 2 + 1 : n / 2;
        int res = 4;
        for(int i = 1; i < m; ++i)
        {
            if(isOdd && i == m - 1) res *= 3;
            else res *= 5;
        }

        return res;
    }

    vector<string> getNums(int n, int m)
    {
        if(m == 0) return {""};
        if(m == 1) return {"0", "1", "8"};

        vector<string> res;
        const auto& r = getNums(n, m - 2);
        for(const auto& i : r)
        {
            if(n != m) res.push_back('0' + i + '0');
            res.push_back('1' + i + '1');
            res.push_back('6' + i + '9');
            res.push_back('9' + i + '6');
            res.push_back('8' + i + '8');
        }

        return res;
    }
};


int main() {
    Solution s;
    std::cout<<s.strobogrammaticInRange("50", "100")<<std::endl;
}
