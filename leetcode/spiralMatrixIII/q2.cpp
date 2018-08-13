#include "header.h"

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<int> ul{r0, c0};
        vector<int> ur{r0, c0 + 1};
        vector<int> lr{r0 + 1, c0 + 1};
        vector<int> ll{r0 + 1, c0};

        int cnt = 0;
        res.push_back(ul);
        ++cnt;
        if(isvalid(ur[0], ur[1], R, C)) {
            res.push_back(ur);
            ++cnt;
        }
        if(isvalid(lr[0], lr[1], R, C)) {
            res.push_back(lr);
            ++cnt;
        }
        if(isvalid(ll[0], ll[1], R, C)) {
            res.push_back(ll);
            ++cnt;
        }

        while(cnt < R * C)
        {
            --ul[0]; --ul[1];
            --ur[0]; ++ur[1];
            ++lr[0]; ++lr[1];
            ++ll[0]; --ll[1];

            for(int i = ll[0] - 1; i >= ul[0]; --i)
            {
                if(isvalid(i, ll[1], R, C)) {
                    res.push_back({i, ll[1]});
                    ++cnt;
                }
            }
            for(int j = ul[1] + 1; j <= ur[1]; ++j)
            {
                if(isvalid(ul[0], j, R, C)) {
                    res.push_back({ul[0], j});
                    ++cnt;
                }
            }
            for(int i = ur[0] + 1; i <= lr[0]; ++i)
            {
                if(isvalid(i, ur[1], R, C)) {
                    res.push_back({i, ur[1]});
                    ++cnt;
                }
            }
            for(int j = lr[1] - 1; j >= ll[1]; --j)
            {
                if(isvalid(lr[0], j, R, C)) {
                    res.push_back({lr[0], j});
                    ++cnt;
                }
            }
        }
        return res;
    }

    bool isvalid(int i, int j, int R, int C)
    {
        return i >= 0 && i < R && j >= 0 && j < C;
    }
};

int main()
{
    Solution s;
    const auto& r = s.spiralMatrixIII(5, 6, 1, 4);
    for(const auto& v : r)
        cout<<v[0]<<" "<<v[1]<<endl;
}
