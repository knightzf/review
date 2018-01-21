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
    int calculate(string s) {
        std::list<std::string> list;
        int n = s.size();
        for(int i = 0; i < n;)
        {
            char c = s[i];
            switch(c)
            {
            case ' ':
                ++i;
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                list.push_back(std::string(1, c));
                ++i;
                break;
            default:
                {
                    int j = i;
                    while(std::isdigit(s[j]) && j < n) ++j;
                    list.push_back(s.substr(i, j - i));
                    i = j;
                    break;
                }
            }
        }

        for(auto iter = list.begin(); iter != list.end();)
        {
            const std::string& str = *iter;
            if(str == "*" || str == "/")
            {
                auto pre = iter; --pre;
                auto pos = iter; ++pos;
                int t = 0;
                if(str == "*")
                {
                    t = std::stoi(*pre) * std::stoi(*pos);
                }
                else
                {
                    t = std::stoi(*pre) / std::stoi(*pos);
                }

                *pre = std::to_string(t);

                iter = list.erase(iter);
                iter = list.erase(iter);
            }
            else
            {
                ++iter;
            }
        }

        int res = 0;
        int oper = 0;
        for(auto iter = list.begin(); iter != list.end(); ++iter)
        {
            const std::string& str = *iter;
            if(str == "+")
            {
                oper = 1;
                continue;
            }
            else if(str == "-")
            {
                oper = -1;
                continue;
            }

            if(oper == 0) res = std::stoi(str);
            else if(oper == 1) res += std::stoi(str);
            else if(oper == -1) res -= std::stoi(str);
        }

        return res;
    }
};

int main() {
    Solution s;
    //std::cout<<s.calculate("1 + 1")<<std::endl;
    //std::cout<<s.calculate(" 2-1 + 2 ")<<std::endl;
    std::cout<<s.calculate("3 + 2* 2")<<std::endl;
}
