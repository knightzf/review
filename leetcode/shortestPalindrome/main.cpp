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
    string shortestPalindrome(string s) {
        if(isPalindrome(s)) return s;

        int n = s.size();

        int pivot = n % 2 == 0 ? n / 2 - 1 : n / 2;

        int i = pivot;
        int j = n % 2 == 0 ? i + 1 : i;

        while(pivot >= 0)
        {
            bool equal = i == j;
            while(s[i] == s[j] && i >= 0)
            {
                --i; ++j;
            }

            if(i < 0)
            {
                //std::cout<<pivot<<std::endl;
                break;
            }
            else
            {
                if(equal)
                {
                    --pivot;
                    i = pivot;
                    j = i + 1;
                }
                else
                {
                    i = pivot;
                    j = pivot;
                }
            }
        }

        //if(pivot == 0) j = 1;

        string t = s.substr(j);
        std::reverse(t.begin(), t.end());

        return t + s;
    }
private:
    bool isPalindrome(const std::string& s)
    {
        if(s.empty()) return true;

        int i = 0;
        int j = s.size() - 1;

        while(i < j)
        {
            if(s[i] != s[j]) return false;

            ++i;
            --j;
        }

        return true;
    }
};

int main() {
    Solution s;
    std::cout<<s.shortestPalindrome("aacecaaa")<<std::endl;
    std::cout<<s.shortestPalindrome("abcd")<<std::endl;
    std::cout<<s.shortestPalindrome("abbacd")<<std::endl;
    std::cout<<s.shortestPalindrome("aabba")<<std::endl;
}
