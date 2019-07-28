#include "header.h"

class Solution {
public:
    string toGoatLatin(string S) {
        static unordered_set<char> s{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string res;
        for(int i = 0, n = S.size(), cnt = 0; i < n; ) {
            if(isalpha(S[i])) {
                ++cnt;
                int j = i;
                while(j < n && isalpha(S[j])) ++j;
                const auto& str = S.substr(i, j - i);
                if(cnt > 1) res += " ";
                if(s.count(str[0])) res += str;
                else res += str.substr(1) + str[0];
                res += "ma" + string(cnt, 'a');
                i = j;
            } else ++i;
        }
        return res;
    }
};


int main()
{
    Solution s;
}