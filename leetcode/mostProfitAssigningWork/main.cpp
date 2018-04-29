#include "header.h"

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = difficulty.size();

        map<int, int> jobs;
        for(int i = 0; i < m; ++i)
        {
            if(jobs.find(difficulty[i]) == jobs.end())
            {
                jobs.emplace(difficulty[i], profit[i]);
            }
            else if(jobs[difficulty[i]] < profit[i])
            {
                jobs[difficulty[i]] = profit[i];
            }
        }

        map<int, int> maxProfitMap;
        for(const auto& p : jobs)
        {
            if(maxProfitMap.empty())
            {
                maxProfitMap.insert(p);
            }
            else
            {
                int t = maxProfitMap.rbegin()->second;
                maxProfitMap[p.first] = (t >= p.second ? t : p.second);
            }
        }

        int res = 0;
        for(int i : worker)
        {
            auto iter = maxProfitMap.lower_bound(i);
            if(iter != maxProfitMap.end())
            {
                if(iter->first == i)
                {
                    res += iter->second;
                }
                else if(iter != maxProfitMap.begin())
                {
                    --iter;
                    res += iter->second;
                }
            }
            else
                res += maxProfitMap.rbegin()->second;
        }
        return res;
    }
};

int main()
{
    Solution s;
    /*vector<int> a{2,4,6,8,10};
    vector<int> b{10,20,30,40,5};
    vector<int> c{4,5,6,7};
    vector<int> a{13, 37, 58};
    vector<int> b{4, 90, 96};
    vector<int> c{34, 73, 45};*/
    vector<int> a{68,35,52,47,86};
    vector<int> b{67,17,1,81,3};
    vector<int> c{92,10,85,84,82};
    std::cout<<s.maxProfitAssignment(a, b, c)<<std::endl;
}
