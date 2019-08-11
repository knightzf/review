#include "header.h"

class Solution {
public:
    using Iter = vector<vector<int>>::iterator;

    template<class Predicate>
    Iter partition(Iter first, Iter last, Predicate p) {
        first = find_if_not(first, last, p);
        if(first == last) return first;
        for(auto iter = next(first); iter != last; ++iter) {
            if(p(*iter)) {
                iter_swap(iter, first++);
            }
        }
        return first;
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto first = points.begin(), last = points.end();
        while(true) {
            auto pivot = *next(first, distance(first, last) / 2);
            auto iter = partition(first, last, [&pivot](const auto& p) {
                return p[0] * p[0] + p[1] * p[1] < pivot[0] * pivot[0] + pivot[1] * pivot[1];
            });
            auto jter = partition(first, last, [&pivot](const auto& p) {
                return p[0] * p[0] + p[1] * p[1] <= pivot[0] * pivot[0] + pivot[1] * pivot[1];
            });
            int dis1 = distance(points.begin(), iter), dis2 = distance(points.begin(), jter);
            if(dis1 <= K && K <= dis2) break;
            else if(dis2 < K) first = jter;
            else last = iter;
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

int main()
{
    Solution s;
}