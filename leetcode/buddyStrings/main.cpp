#include "header.h"

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        int n = A.size();
        if(n < 2) return false;

        vector<int> diff;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] != B[i]) diff.emplace_back(i);
        }

        if(diff.size() == 2 && A[diff[0]] == B[diff[1]] && B[diff[0]] == A[diff[1]]) return true;

        if(diff.empty())
        {
            vector<bool> v(26, false);
            for(int i = 0; i < n; ++i)
            {
                if(v[A[i] - 'a'] == false)
                    v[A[i] - 'a'] = true;
                else
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
}
