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
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n < 3) return false;

        if(num[0] == '0')
        {
            return impl(num, "0", "", 1, n, 1);
        }

        for(int i = 1; i <= n / 2; ++i)
        {
            if(impl(num, num.substr(0, i), "", i, n, 1)) return true;
        }

        //std::cout<<add("123", "45")<<std::endl;

        return false;
    }
private:
    bool impl(const std::string& num, const std::string& num1, const std::string& num2,
              int startIdx, int n, int cnt)
    {
        //std::cout<<num1<<" "<<num2<<" startidx "<<startIdx<<std::endl;
        if(cnt == 1)
        {
            if(num[startIdx] == '0')
            {
                return impl(num, num1, "0", startIdx + 1, n, 2);
            }

            int len = 1;
            while(max(startIdx, len) <= n - startIdx - len)
            {
                const auto& t = num.substr(startIdx, len);
                if(impl(num, num1, t, startIdx + len, n, 2)) return true;
                ++len;
            }
        }
        else
        {
            if(startIdx == n) return true;

            const auto& t = add(num1, num2);
            //std::cout<<num1<<" "<<num2<<" "<<t<<std::endl;
            //std::cout<<"check "<<num.substr(startIdx, t.size())<<std::endl;
            if(n - startIdx >= t.size() && num.substr(startIdx, t.size()) == t)
            {
                //std::cout<<"here"<<std::endl;
                return impl(num, num2, t, startIdx + t.size(), n, cnt + 1);
            }
        }

        return false;
    }

    string add(const std::string& num1, const std::string& num2)
    {
        int m = num1.size();
        int n = num2.size();

        int borrow = 0;
        string res = string(max(m, n), '0');

        for(int i = res.size() - 1; i >= 0; --i)
        {
            int t = borrow;
            if(m > 0)
            {
                t += num1[m - 1] - '0';
                --m;
            }
            if(n > 0)
            {
                t += num2[n - 1] - '0';
                --n;
            }

            if(t > 9)
            {
                res[i] = t % 10 + '0';
                borrow = 1;
            }
            else
            {
                res[i] = t + '0';
                borrow = 0;
            }
        }

        if(borrow)
        {
            return "1" + res;
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout<<s.isAdditiveNumber("112358")<<std::endl;
    std::cout<<s.isAdditiveNumber("199100199")<<std::endl;
}
