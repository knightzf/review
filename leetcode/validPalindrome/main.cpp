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
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            while(!std::isalnum(s[i])) ++i;
            while(!std::isalnum(s[j])) --j;
            if(i < j)
            {
                if(s[i] != s[j] && std::toupper(s[i]) != std::toupper(s[j]))
                    return false;
                ++i;
                --j;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    std::cout<<s.isPalindrome("0P")<<std::endl;
}
