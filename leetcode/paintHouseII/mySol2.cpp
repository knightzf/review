#include "header.h"

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        vector<int> last(k, 0);
        vector<int> minIdx{0, 0};
        int res = INT_MAX;
        for(int i = 0; i < n; ++i) {
            vector<int> temp(k);
            vector<int> tminIdx;
            int tempRes = INT_MAX;
            for(int j = 0; j < k; ++j) {                
                temp[j] = last[minIdx[0]] + costs[i][j];
                if(j == minIdx[0]) {
                    temp[j] = last[minIdx[1]] + costs[i][j];
                }
                if(tminIdx.empty()) tminIdx.push_back(j);
                else if(tminIdx.size() == 1) {
                    if(temp[j] >= temp[tminIdx[0]]) tminIdx.push_back(j);
                    else {
                        tminIdx.push_back(tminIdx.back());
                        tminIdx[0] = j;
                    }
                } else {
                    if(temp[j] < temp[tminIdx[0]]) {
                        tminIdx[1] = tminIdx[0];
                        tminIdx[0] = j;
                    }
                    else if (temp[j] < temp[tminIdx[1]]) tminIdx[1] = j;
                }
                tempRes = min(temp[j], tempRes);
            }
            last = temp;
            minIdx = tminIdx;
            res = tempRes;
        }
        return res;
    }
};

int main()
{
    //Solution s;
}