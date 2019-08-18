#include "header.h"

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double, int>> rate(n);
        for(int i = 0; i < n; ++i) {
            rate[i] = {wage[i] / double(quality[i]), quality[i]};
        }
        sort(rate.begin(), rate.end());

        double currRate = rate[K - 1].first;
        int totalQuantity = 0;
        priority_queue<int> qualities;
        for(int i = 0; i < K; ++i) {
            totalQuantity += rate[i].second;
            qualities.push(rate[i].second);
        }
        double res = totalQuantity * currRate;
        for(int i = K; i < n; ++i) {
            currRate = rate[i].first;
            if(rate[i].second < qualities.top()) {
                totalQuantity -= qualities.top();
                totalQuantity += rate[i].second;
                qualities.pop();
                qualities.push(rate[i].second);
                res = min(res, totalQuantity * currRate);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}