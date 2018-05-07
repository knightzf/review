#include "header.h"

class Solution {
public:
    int uniqueLetterString(string S) {
        if(S.empty()) return 0;
        std::for_each(S.begin(), S.end(), [](char& c){
                      c = std::tolower(c);});

        vector<vector<int>> v(26);
        int n = S.size();
        for(int i = 0; i < n; ++i)
        {
            v[S[i] - 'a'].push_back(i);
        }

        long res = 0;
        for(int i = 0; i < 26; ++i)
        {
            for(int j = 0; j < v[i].size(); ++j)
            {
                if(j == 0)
                {
                    res += (v[i][j] + 1) * ((j == v[i].size() - 1) ? (n - v[i][j]) : (v[i][j + 1] - v[i][j]));
                }
                else
                {
                    res += (v[i][j] - v[i][j - 1]) * ((j == v[i].size() - 1) ? (n - v[i][j]) : (v[i][j + 1] - v[i][j]));
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.uniqueLetterString("ABA")<<std::endl;
    std::cout<<s.uniqueLetterString("ABC")<<std::endl;
}
