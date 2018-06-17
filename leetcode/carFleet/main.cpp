#include "header.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; ++i)
        {
            v.emplace_back(position[i], speed[i]);
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if(a.first < b.first) return true;
            if(a.first == b.first) return a.second > b.second;
            return false;
        });

        int res = 0;
        //for(int i = 0; i < n; ++i)
        for(int i = n - 1; i >= 0;)
        {
            if(i == 0)
            {
                ++res;
                break;
            }

            int j = i - 1;
            while(j >= 0 &&
                  (target - v[i].first) * (double)v[j].second >= (target - v[j].first) * (double)v[i].second) --j;
            ++res;
            i = j;
        }
        return res;
    }
};

int main()
{
}
