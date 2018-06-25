#include "header.h"

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if(picture.empty() || picture[0].empty()) return 0;

        int m = picture.size(), n = picture[0].size();
        sort(picture.begin(), picture.end(), [](const auto& a, const auto& b){
                return a < b;
             });
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(picture[i][j] == 'B')
                {
                    ++row[i];
                    ++col[j];
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m;)
        {
            int j = i;
            while(j <m && picture[j] == picture[i]) ++j;
            if(j - i >= N && row[i] == N)
            {
                for(int a = 0; a < n; ++a)
                {
                    if(picture[i][a] == 'B' && col[a] == N)
                    {
                        res += j - i;
                    }
                }
            }

            i = j;
        }
    }
};

int main()
{
    Solution s;
}
