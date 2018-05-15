#include "header.h"

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
                if(a.first < b.first) return true;
                else if(a.first == b.first) return a.second < b.second;
                return false;
             });
        //for(const auto& p : points)
        //    std::cout<<p.first<<" "<<p.second<<std::endl;
        int n = points.size();
        int res = 0;
        for(int i = 0; i < n;)
        {
            int j = i + 1;
            int maxRight = points[i].second;
            while(j < n && maxRight >= points[j].first)
            {
                maxRight = min(maxRight, points[j].second);
                ++j;

            }

            ++res;
            i = j;
        }
        return res;
    }
};

int main()
{
    Solution s;
    //vector<pair<int, int>> a{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
    vector<pair<int, int>> a{{0,9},{1,8},{7,8},{1,6},{9,16},{7,13},{7,10},{6,11},{6,9},{9,13}};
    cout<<s.findMinArrowShots(a)<<endl;
}
