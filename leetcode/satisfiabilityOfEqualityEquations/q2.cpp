#include "header.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        unordered_map<int, int> m;
        for(int i = 'a'; i <= 'z'; ++i) m[i] = i;

        function<int(int)> root = [&](int i)
        {
            while (i != m[i])
            {
                m[i] = m[m[i]];
                i = m[i];
            }
            return i;
        };

        function<bool(int, int)> find = [&](int p, int q)
        {
            return root(p) == root(q);
        };

        function<void(int, int)> unite = [&](int p, int q)
        {
            int i = root(p);
            int j = root(q);
            m[i] = j;
        };

        for(int i = 0; i < n; ++i)
        {
            if(equations[i][1] == '=')
            {
                unite(equations[i][0], equations[i][3]);
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(equations[i][1] == '!')
            {
                int k = root(int(equations[i][0]));
                int j = root(int(equations[i][3]));
                if(k == j) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> a{"a==b","b!=a"};
    cout<<s.equationsPossible(a)<<endl;
}
