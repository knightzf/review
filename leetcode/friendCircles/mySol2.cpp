#include "header.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> p(n, 0);
        function<int(int)> findParent = [&](int i) {
            while(p[i] != i) {
                p[i] = p[p[i]];
                i = p[i];
            }
            return i;
        };
        for(int i = 0; i < n; ++i) p[i] = i;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(M[i][j]) {
                    int pa = findParent(i);
                    int pb = findParent(j);
                    if(pa != pb) {
                        p[pa] = pb;
                    }
                }
            }
        }
        unordered_set<int> s;
        for(int i = 0; i < n; ++i) {
            s.insert(findParent(i));
        }
        return s.size();
    }
};

int main()
{
    //Solution s;
}