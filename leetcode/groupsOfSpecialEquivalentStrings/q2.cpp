#include "header.h"

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> ss;
        for(string& s : A)
        {
            convert(s);
            ss.insert(s);
        }
        return ss.size();
    }

    void convert(string& s)
    {
        string t1;
        string t2;
        for(int i = 0, n = s.size(); i < n; ++i)
        {
            if(i % 2 == 0) t1 += s[i];
            else t2 += s[i];
        }

        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        s = t1 + t2;
    }
};

int main()
{
    Solution s;
}
