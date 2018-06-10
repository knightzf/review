#include "header.h"

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size();
        int m = 0;
        string res = S;
        for(int i = n - 1; i >= 0; --i)
        {
            m += shifts[i];
            m %= 26;
            char t = (S[i] + m - 'a') % 26 + 'a';
            //cout<<m<<" "<<(int)t<<endl;
            res[i] = t;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{26, 9, 17};
    cout<<s.shiftingLetters("ruu", a)<<endl;
}
