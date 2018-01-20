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
#include <iterator>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        return impl(s, 0, s.size());
    }

    int impl(const std::string& s, int startIdx, int endIdx)
    {
        int res = 0;
        int oper = 0; // 1: + -1: -

        for(int i = startIdx; i < endIdx;)
        {
            char c = s[i];
            //std::cout<<"c "<<c<<std::endl;
            switch(c)
            {
            case ' ':
                ++i;
                break;
            case '(':
                {
                    int j = i + 1;
                    int leftP = 1;
                    while(leftP != 0 && j < endIdx)
                    {
                        if(s[j] == '(') ++leftP;
                        else if(s[j] == ')') --leftP;
                        ++j;
                    }
                    int r = impl(s, i + 1, j - 1);
                    switch(oper)
                    {
                    case 1:
                        res += r;
                        break;
                    case -1:
                        res -= r;
                        break;
                    default:
                        res = r;
                        break;
                    }
                    i = j;
                    break;
                }
            case '+':
                ++i;
                oper = 1;
                break;
            case '-':
                ++i;
                oper = -1;
                break;
            default:
                {
                    int j = i;
                    while(std::isdigit(s[j]) && j < endIdx) ++j;
                    //std::cout<<"j "<<j<<std::endl;
                    int num = std::stoi(s.substr(i, j - i));
                    //std::cout<<i<<" "<<j<<" "<<num<<std::endl;
                    switch(oper)
                    {
                    case 1:
                        res += num;
                        break;
                    case -1:
                        res -= num;
                        break;
                    default:
                        res = num;
                        break;
                    }
                    i = j;
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    //std::cout<<s.calculate("1 + 1")<<std::endl;
    //std::cout<<s.calculate(" 2-1 + 2 ")<<std::endl;
    std::cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<std::endl;
}
