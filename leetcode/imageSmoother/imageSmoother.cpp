#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        std::vector<std::vector<int>> result = M;
        size_t height = M.size();
        size_t width = M[0].size();

        for(size_t i = 0; i < height; ++i)
        {
            for(size_t j = 0; j < width; ++j)
            {
                double sum = M[i][j];
                int count = 1;
                if(i != 0)
                {
                    sum += M[i - 1][j];
                    ++count;

                    if(j != 0)
                    {
                        sum += M[i - 1][j -1];
                        ++count;
                    }
                }

                if(i != height - 1)
                {
                   sum += M[i + 1][j];
                   ++count;

                   if(j != width - 1)
                   {
                       sum += M[i + 1][j + 1];
                       ++count;
                   }
                }

                if(j != 0)
                {
                    sum += M[i][j - 1];
                    ++count;

                    if(i != height - 1)
                    {
                        sum += M[i + 1][j -1];
                        ++count;
                    }
                }

                if(j != width - 1)
                {
                    sum += M[i][j + 1];
                    ++count;

                    if(i != 0)
                    {
                        sum += M[i - 1][j  + 1];
                        ++count;
                    }
                }

                result[i][j] = floor(sum / count);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> a{
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
    };
    vector<vector<int>> b = sol.imageSmoother(a);

    for(auto& item : b)
    {
        for(auto& it : item)
            std::cout<<it<<" ";
        std::cout<<endl;
    }


	return 0;
}
