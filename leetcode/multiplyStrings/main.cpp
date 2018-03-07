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
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size()) std::swap(num1, num2);

        std::string res;

        int n = num2.size();
        for(int i = 0; i < n; ++i)
        {
            std::string t = mul(num1, num2[i]);
            //std::cout<<num1<<" "<<num2[i]<<" "<<t<<std::endl;
            std::string z(n - i - 1, '0');
            t += z;
            add(res, t);
        }

        int i = 0;
        while(i < res.size() - 1 && res[i] == '0') ++i;

        return res.substr(i);
    }

    string mul(const std::string& s, char c)
    {
        int digit = c - '0';
        std::string res(s.size() + 1, '0');
        int borrow = 0;
        int idx = res.size() - 1;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            int t = (s[i] - '0') * digit + borrow;
            if(t >= 10)
            {
                res[idx] = (t % 10) + '0';
                borrow = t / 10;
            }
            else
            {
                res[idx] = t + '0';
                borrow = 0;
            }
            --idx;
        }
        if(borrow != 0)
        {
            res[0] = borrow + '0';
            return res;
        }

        return res.substr(1);
    }

    void add(std::string& a, std::string& b)
    {
        if(a.size() < b.size())
        {
            a = std::string(b.size() - a.size(), '0') + a;
        }
        else if(a.size() > b.size())
        {
            b = std::string(a.size() - b.size(), '0') + b;
        }

        int borrow = 0, n = a.size();
        for(int i = n - 1; i >= 0; --i)
        {
            int t = a[i] - '0' + b[i] - '0' + borrow;
            if(t >= 10)
            {
                a[i] = t % 10 + '0';
                borrow = t / 10;
            }
            else
            {
                a[i] = t + '0';
                borrow = 0;
            }
        }

        if(borrow != 0)
        {
            a = char(borrow + '0') + a;
        }
    }
};



int main() {
    Solution s;
    std::cout<<s.multiply("123", "456")<<std::endl;
    std::cout<<s.multiply("9", "9")<<std::endl;
    std::cout<<s.multiply("9133", "0")<<std::endl;
}
