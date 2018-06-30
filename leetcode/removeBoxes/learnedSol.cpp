#include "header.h"

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> m(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return impl(boxes, m, 0, n - 1, 0);
    }

    int impl(vector<int>& boxes, vector<vector<vector<int>>>& m, int i, int j, int k)
    {
        //cout<<i<<" "<<j<<" "<<k<<endl;
        if(i == j) return (k + 1) * (k + 1);
        if(i > j) return 0;
        if(m[i][j][k] > 0) return m[i][j][k];


        int res = (k + 1) * (k + 1) + impl(boxes, m, i + 1, j, 0);
        for(int p = i + 1; p <= j; ++p)
        {
            if(boxes[p] == boxes[i])
            {
                res = max(res,
                          impl(boxes, m, i + 1, p - 1, 0) + impl(boxes, m, p, j, k + 1));
            }
        }

        m[i][j][k] = res;
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{3,8,8,5,5,3,9,2,4,4,6,5,8,4,8,6,9,6,2,8,6,4,1,9,5,3,10,5,3,3,9,8,8,6,5,3,7,4,9,6,3,9,4,3,5,10,7,6,10,7};
    vector<int> a{1,3,2,2,2,3,4,3,1};
    cout<<s.removeBoxes(a)<<endl;;
}
