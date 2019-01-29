#include "header.h"

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int n = min(A, B);
        vector<string> v(n, "ab");
        if(A > B)
        {
            for(int i = 0; i < min(n, A - B); ++i) v[i] = "aab";
            if(A - B > n) v.push_back(string(A - B - n, 'a'));
        }
        else
        {
            for(int i = 0; i < min(n, B - A); ++i) v[i] = "abb";
            if(B - A > n) v.insert(v.begin(), string(B - A - n, 'b'));
        }
        
        string res;
        for(const auto& s : v) res += s;
        return res;
    }
};

int main()
{
    Solution s;
}
