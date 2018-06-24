#include "header.h"

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<pair<double, int>> v;
        for(int i = 0; i < n; ++i)
            v.emplace_back(double(wage[i]) / quality[i], quality[i]);

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
                return a.first < b.first;
             });

        /*for(const auto& p : v)
            cout<<p.first<<" "<<p.second<<endl;
        cout<<endl;*/

        double res = INT_MAX;
        multiset<int> workers;
        for(int i = 0; i < n; ++i)
        {
            if(workers.size() >= K - 1)
            {
                double t = v[i].first * v[i].second;

                auto iter = workers.begin();
                for(int j = 0; j < K - 1; ++j)
                {
                    t += *iter * v[i].first;
                    ++iter;
                }

                res = min(res, t);
            }
            workers.insert(v[i].second);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{10, 20, 5};
    vector<int> b{70,50,30};
    cout<<s.mincostToHireWorkers(a, b, 2)<<endl;;
}
