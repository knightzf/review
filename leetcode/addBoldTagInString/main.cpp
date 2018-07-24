#include "header.h"

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<bool> v(n, false);

        for(const auto& w : dict)
        {
            int startIdx = 0;

            while(true)
            {
                int pos = s.find(w, startIdx);
                if(pos != -1)
                {
                    for(int i = pos; i < pos + w.size(); ++i)
                        v[i] = true;
                    startIdx = pos + 1;
                }
                else break;
            }
        }

        string res;
        for(int i = 0; i < n;)
        {
            if(v[i] == false)
            {
                res += s[i];
                ++i;
            }
            else
            {
                int j = i;
                while(j < n && v[j]) ++j;
                res += "<b>" + s.substr(i, j - i) + "</b>";
                i = j;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
}
