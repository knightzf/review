#include "header.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int bottomX = INT_MAX, bottomY = INT_MAX, topX = INT_MIN, topY = INT_MIN;
        int cnt = 0;
        unordered_set<string> s;
        for(const auto& v : rectangles)
        {
            bottomX = min(bottomX, v[1]);
            bottomY = min(bottomY, v[0]);

            topX = max(topX, v[3]);
            topY = max(topY, v[2]);

            cnt += (v[2] - v[0]) * (v[3] - v[1]);

            string s1 = std::to_string(v[1]) + " " + std::to_string(v[0]);
            string s2 = std::to_string(v[1]) + " " + std::to_string(v[2]);
            string s3 = std::to_string(v[3]) + " " + std::to_string(v[2]);
            string s4 = std::to_string(v[3]) + " " + std::to_string(v[0]);

            if(s.find(s1) == s.end()) s.insert(s1);
            else s.erase(s1);
            if(s.find(s2) == s.end()) s.insert(s2);
            else s.erase(s2);
            if(s.find(s3) == s.end()) s.insert(s3);
            else s.erase(s3);
            if(s.find(s4) == s.end()) s.insert(s4);
            else s.erase(s4);
        }

        if(s.find(std::to_string(topX) + " " + std::to_string(topY)) == s.end() ||
           s.find(std::to_string(topX) + " " + std::to_string(bottomY)) == s.end() ||
           s.find(std::to_string(bottomX) + " " + std::to_string(topY)) == s.end() ||
           s.find(std::to_string(bottomX) + " " + std::to_string(bottomY)) == s.end() ||
           s.size() != 4
           )
            return false;

        return cnt == (topX - bottomX) * (topY - bottomY);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    std::cout<<s.isRectangleCover(a)<<std::endl;
}
