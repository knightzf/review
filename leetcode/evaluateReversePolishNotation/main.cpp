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
    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> s;

        for(const auto& token : tokens)
        {
            if(!isOperator(token))
            {
                s.push(token);
            }
            else
            {
                int b = std::stoi(s.top());
                s.pop();
                int a = std::stoi(s.top());
                s.pop();
                int res = calc(a, token, b);
                s.push(std::to_string(res));
            }
        }

        return std::stoi(s.top());
    }

    bool isOperator(const std::string& s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int calc(int a, const std::string& oper, int b)
    {
        char c = oper[0];
        switch(c)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return a /b;
        }
    }
};


int main()
{
    Solution s;
    std::vector<std::string> a{"4", "13", "5", "/", "+"};
    std::cout<<s.evalRPN(a)<<std::endl;
}
