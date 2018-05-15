#include "header.h"

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<char,int>> v(256);
        for(int i = 0; i < n; ++i)
        {
            v[s[i]] = make_pair(s[i], v[s[i]].second + 1);
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
                return a.second > b.second;
             });

        string res;
        for(int i = 0; i < 256; ++i)
        {
            if(v[i].second == 0)
                break;
            res += string(v[i].second, v[i].first);
        }
        return res;
    }
};

int main()
{
    Solution s;
}
