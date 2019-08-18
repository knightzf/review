#include "header.h"

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        map<vector<double>, map<int, vector<vector<int>>>> m;

        auto dis = [&](const vector<int>& a, const vector<int>& b) {
            return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
        };

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                double x = (points[i][0] + points[j][0]) / 2.0;
                double y = (points[i][1] + points[j][1]) / 2.0;
                long d = dis(points[i], points[j]);
                m[{x, y}][d].emplace_back(vector<int>{i, j});
            }
        }

        auto area = [&](const vector<int>& a, const vector<int>& b) {
            const auto& p1 = points[a[0]];
            const auto& p2 = points[b[0]];
            const auto& p4 = points[b[1]];
            return sqrt(dis(p1, p2)) * sqrt(dis(p1, p4));
        };

        double res = INT_MAX;
        for(const auto& p : m) {
            for(const auto& q : p.second) {
                if(q.second.size() > 1) {
                    for(int i = 0, n = q.second.size(); i < n; ++i) {
                        for(int j = i + 1; j < n; ++j) {
                            const auto& p1 = q.second[i];
                            const auto& p2 = q.second[j];
                            res = min(res, area(p1, p2));
                        }
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution s;
}