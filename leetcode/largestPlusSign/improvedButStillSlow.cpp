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

        std::unordered_map<int, std::unordered_set<int>> xMap;
        std::unordered_map<int, std::unordered_set<int>> yMap;

        for(const auto& v : mines)
        {
            xMap[v[0]].insert(v[1]);
            yMap[v[1]].insert(v[0]);
        }

        while(largestOrder)
        {
            for(int i = largestOrder - 1; i <= N - largestOrder; ++i)
            {
                for(int j = largestOrder - 1; j <= N - largestOrder; ++j)
                {
                    bool found = true;

                    if(xMap.find(i) != xMap.end())
                    {
                        for(int k = j - largestOrder + 1; k < j + largestOrder; ++k)
                        {
                            if(xMap[i].find(k) != xMap[i].end())
                            {
                                found = false;
                                break;
                            }
                        }
                    }

                    if(!found) continue;

                    if(yMap.find(j) != yMap.end())
                    {
                        for(int k = i - largestOrder + 1; k < i + largestOrder; ++k)
                        {
                            if(yMap[j].find(k) != yMap[j].end())
                            {
                                found = false;
                                break;
                            }
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
