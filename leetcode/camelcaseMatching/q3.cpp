#include "header.h"

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> res(n, false);
        for(int i = 0; i < n; ++i)
        {
            if(match(queries[i], pattern)) res[i] = true;
        }
        return res;
    }

    bool match(const string& query, const string& pattern)
    {
        int m = query.size(), n = pattern.size();
        int i = 0, j = 0;

        while(i < m && j < n)
        {
            if(query[i] == pattern[j]) {
                ++i; ++j;
            } else {
                if(islower(query[i])) ++i;
                else return false;
            }
        }
        if(j < n) return false;
        if(i < m) return all_of(query.begin() + i, query.end(), ::islower);
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> a{"FooBar"};
    s.camelMatch(a, "FB");
}

