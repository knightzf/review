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
    bool isScramble(string s1, string s2)
    {
        if(s1.size() != s2.size())
        {
            return false;
        }

        if(s1.size() == 1)
        {
            return s1 == s2;
        }

        if(s1 == s2)
        {
            return true;
        }

        int len = 1;
        while(len < s1.size())
        {
            std::string a = s1.substr(0, len);
            std::string b = s2.substr(0, len);
            std::string c = s2.substr(s2.size() - len, len);

            std::cout<<len<<" "<<areSame(a, b)<<" "<<areSame(a, c)<<std::endl;
            std::cout<<a<<" "<<b<<" "<<c<<std::endl;

            bool f1 = areSame(a, b);
            bool f2 = areSame(a, c);

            if(f1 || f2)
            {
                if(f1 && f2)
                {
                    return (isScramble(a, b) &&
                            isScramble(s1.substr(len, s1.size() - len), s2.substr(len, s2.size() - len)))
                            ||
                            (isScramble(a, c) &&
                            isScramble(s1.substr(len, s1.size() - len), s2.substr(0, s2.size() - len)));
                }
                else
                {
                    if(f1)
                    {
                        return isScramble(a, b) &&
                            isScramble(s1.substr(len, s1.size() - len), s2.substr(len, s2.size() - len));
                    }
                    else
                    {
                        return isScramble(a, c) &&
                            isScramble(s1.substr(len, s1.size() - len), s2.substr(0, s2.size() - len));
                    }
                }
            }

            ++len;
        }

        return false;
    }

    bool areSame(const std::string& a, const std::string& b)
    {
        std::string s1 = a;
        std::string s2 = b;
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        return s1 == s2;
    }
};

int main()
{
    Solution s;
    /*std::cout<<s.isScramble("rgtae", "great")<<std::endl;
    std::cout<<s.isScramble("a", "b")<<std::endl;
    std::cout<<s.isScramble("abcd", "bdac")<<std::endl;
    std::cout<<s.isScramble("hobobyrqd", "hbyorqdbo")<<std::endl;
    */std::cout<<s.isScramble("cbcccccbbabcbac", "bbccaccbcbcabcc")<<std::endl;
}
