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

        if(s1 == s2)
        {
            return true;
        }

        if(!areSame(s1, s2))
        {
            return false;
        }

        int len = s1.size();
        for(int i = 1; i < len; ++i)
        {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
            {
                return true;
            }

            if(isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
            {
                return true;
            }
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
