#include "header.h"

class Solution {
public:
    struct Count
    {
        unordered_map<long, int> incomplete;
        unordered_map<long, int> complete;
    };

    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<Count> v(n);
        int res = 0;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                long diff = (long)A[i] - A[j];
                if(v[j].complete.find(diff) != v[j].complete.end())
                {
                    v[i].complete[diff] += v[j].complete[diff];
                }

                if(v[j].incomplete.find(diff) != v[j].incomplete.end())
                {
                    v[i].complete[diff] += v[j].incomplete[diff];
                }

                ++v[i].incomplete[diff];
            }
        }
        for(int i = 1; i < n; ++i)
        {
            /*std::cout<<i<<" incomp"<<std::endl;
            for(const auto& p : v[i].incomplete)
                std::cout<<p.first<<" "<<p.second<<std::endl;
            std::cout<<i<<" comp"<<std::endl;
            for(const auto& p : v[i].complete)
                std::cout<<p.first<<" "<<p.second<<std::endl;*/
            for(const auto& p : v[i].complete)
                res += p.second;
        }
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //vector<int> a{2, 4, 6, 8, 10};
    //vector<int> a{0,2000000000,-294967296};
    vector<int> a{1, 1, 1, 1};
    std::cout<<s.numberOfArithmeticSlices(a)<<std::endl;
}
