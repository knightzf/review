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
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int largestOrder = (N - 1) / 2 + 1;
        std::set<std::pair<int, int>> mineSet;
        for(const auto& v : mines)
        {
            mineSet.insert(std::make_pair(v[0], v[1]));
        }

        while(largestOrder)
        {
            for(int i = largestOrder - 1; i <= N - largestOrder; ++i)
            {
                for(int j = largestOrder - 1; j <= N - largestOrder; ++j)
                {
                    if(mineSet.find(std::make_pair(i, j)) != mineSet.end())
                    {
                        continue;
                    }

                    bool found = true;
                    for(int k = j - largestOrder + 1; k < j + largestOrder; ++k)
                    {
                        if(mineSet.find(std::make_pair(i, k)) != mineSet.end())
                        {
                            found = false;
                            break;
                        }
                    }

                    if(!found) continue;

                    for(int k = i - largestOrder + 1; k < i + largestOrder; ++k)
                    {
                        if(mineSet.find(std::make_pair(k, j)) != mineSet.end())
                        {
                            found = false;
                            break;
                        }
                    }

                    if(!found) continue;

                    return largestOrder;
                }
            }

            --largestOrder;
        }

        return 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{4, 2}};
    std::cout<<s.orderOfLargestPlusSign(5, a)<<std::endl;
    vector<vector<int>> b;
    std::cout<<s.orderOfLargestPlusSign(2, b)<<std::endl;
    vector<vector<int>> c{{0, 0}};
    std::cout<<s.orderOfLargestPlusSign(1, c)<<std::endl;
}
