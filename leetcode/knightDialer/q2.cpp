#include "header.h"

class Solution {
public:
    int knightDialer(int N) {
        long res = 0;
        for(int i = 0; i < 10; ++i)
        {
            cout<<i<<" "<<impl(i, N - 1)<<endl;
            res += impl(i, N - 1);
            res %= int(1e9 + 7);
        }
        return res;
    }

    int impl(int i, int n)
    {
        static unordered_map<int, vector<int>> moves{
            {0, {4, 6}},
            {1, {6, 8}},
            {2, {7, 9}},
            {3, {4, 8}},
            {4, {3, 9, 0}},
            {5, {}},
            {6, {1, 7, 0}},
            {7, {2, 6}},
            {8, {1, 3}},
            {9, {2, 4}}
        };
        if(n == 0) return 1;
        if(i == 5) return 0;
        static map<pair<int, int>, int> m;
        auto p = make_pair(i, n);
        long res = 0;
        if(m.find(p) == m.end())
        {
            for(int j : moves[i])
            {
                res += impl(j, n - 1);
            }
            res %= int(1e9 + 7);
            m[p] = res;
        }
        return m[p];
    }
};

int main()
{
    Solution s;
    s.knightDialer(2);
}
