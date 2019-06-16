#include "header.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> ss;
        for(char c : s) {
            if(ss.count(c)) ss.erase(c);
            else ss.insert(c);
        }
        return ss.size() <= 1;
    }
};

int main()
{
    //Solution s;
}