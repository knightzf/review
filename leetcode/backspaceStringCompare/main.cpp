#include "header.h"

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return impl(S) == impl(T);
    }

    string impl(const string& s)
    {
        string res;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != '#')
            {
                res += s[i];
            }
            else if(res.size() > 0)
            {
                res.pop_back();
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.backspaceCompare("a#c", "b")<<endl;
}
