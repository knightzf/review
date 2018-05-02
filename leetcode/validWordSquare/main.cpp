#include "header.h"

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if(words.empty() || words[0].empty()) return true;
        int m = words.size(), n = words[0].size();
        if(m != n) return false;
        for(int i = 0; i < m; ++i)
        {
            string t;
            for(int j = 0; j < m; ++j)
            {
                if(words[j].size() > i)
                    t += words[j][i];
                else
                    break;
            }

            if(words[i] != t) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> a{"abcd","bnrt","crmy","dtye"};
    s.validWordSquare(a);
}
