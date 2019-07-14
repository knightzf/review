#include "header.h"

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        function<void(int)> dfs = [&](int x) {
            for(int i = 0; i < 10; ++i) {
                if(x + i > n) return;
                res.push_back(x + i);
                dfs((x + i) * 10);
            }
        };
        for(int i = 1; i < 10; ++i) {
            if(i <= n) {
                res.push_back(i);
                dfs(i * 10);
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}