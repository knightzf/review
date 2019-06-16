#include "header.h"

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()) swap(str1, str2);
        int m = str1.size(), n = str2.size();
        for(int i = n; i >= 1; --i) {
            if(n % i == 0 && m % i == 0 &&
                divide(str2, str2.substr(0, i)) && divide(str1, str2.substr(0, i)))
                return str2.substr(0, i);
        }
        return "";
    }
    
    bool divide(const string& s, const string& t) {
        for(int j = 0; j < t.size(); ++j) {
            for(int i = 0; i < s.size() / t.size(); ++i) {
                if(s[i * t.size() + j] != t[j]) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
}
