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
    vector<string> addOperators(string num, int target) {
        int n = num.size();
        if(n == 0) return vector<string>();

        vector<string> v = impl(num, 0, n);

        for(auto iter = v.begin(); iter != v.end();)
        {
            if(!valid(*iter, target))
            {
                iter = v.erase(iter);
            }
            else
            {
                ++iter;
            }
        }

        return v;
    }

    bool valid(const std::string& s, int target)
    {
        std::vector<long> nums;
        std::vector<char> opers;

        int startIdx = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!std::isdigit(s[i]))
            {
                long t = std::stol(s.substr(startIdx, i));
                nums.push_back(t);
                opers.push_back(s[i]);
                startIdx = i + 1;
            }
            else if(i == s.size() - 1)
            {
                long t = std::stol(s.substr(startIdx, i));
                nums.push_back(t);
            }
        }

        int res = nums[0];
        for(int i = 0; i < opers.size(); ++i)
        {
            if(i != 0 && opers[i] == '*' && opers[i - 1] != '*')
            {
                if(opers[i - 1] == '+')
                {
                    res -= nums[i];
                }
                else
                {
                    res += nums[i];
                }

                res = calc(res, opers[i - 1], calc(nums[i], '*', nums[i + 1]));
            }
            else
            {
                res = calc(res, opers[i], nums[i + 1]);
            }
        }

        //std::cout<<s<<" "<<res<<std::endl;

        return res == target;
    }

    long calc(long a, char c, long b)
    {
        switch(c)
        {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            default : throw std::bad_alloc();
        }
    }

    vector<string> impl(const std::string& num, int startIdx, int n)
    {
        vector<string> res;

        if(startIdx == n) return res;
        if(startIdx == n - 1)
        {
            res.push_back(num.substr(startIdx, 1));
            return res;
        }

        for(int i = 1; i < n - startIdx + 1; ++i)
        {
            if(i != 1 && num[startIdx] == '0') break;

            const auto& pref = num.substr(startIdx, i);
            const auto& r = impl(num, startIdx + i, n);
            for(const auto& j : r)
            {
                res.push_back(pref + "+" + j);
                res.push_back(pref + "-" + j);
                res.push_back(pref + "*" + j);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    //const auto& r = s.addOperators("105", 5);
    const auto& r = s.addOperators("3456237490", 9191);
    for(auto i : r)
    {
        std::cout<<i<<std::endl;
    }
}
