#include "header.h"

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, unordered_map<int, int>> m;
        int n = A.size();
        for(int i = 0; i < n; ++i)
        {
            for(char c : A[i])
            {
                ++m[c][i];
            }
        }

        vector<string> res;
        for(const auto& p : m)
        {
            if(p.second.size() == n)
            {
                int t = n;
                for(const auto& q : p.second) t = min(t, q.second);
                for(int i = 0; i < t; ++i)res.push_back(string(1, p.first));
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
