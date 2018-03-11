#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
    int bestRotation(vector<int>& A) {
        int n = A.size();
        if(n < 2) return 0;

        int maxScore = 0;
        int bestRotate = 0;
        std::unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
        {
            int diff = i - A[i];
            ++m[diff];

            if(diff >= 0)
            {
                ++maxScore;
            }
        }

        std::unordered_map<int, int> rotatedMap;
        int lastScore = maxScore;

        for(int i = 0; i < n - 1; ++i)
        {
            int localMaxScore = lastScore;

            int diff = i - A[i];
            --m[diff];

            if(diff - i >= 0) --localMaxScore;

            auto iter = m.find(i);
            if(iter != m.end())
            {
                localMaxScore -= iter->second;
            }
            if(i > 0)
            {
                auto iter = rotatedMap.find(i - 1);
                if(iter != rotatedMap.end())
                {
                    localMaxScore -= iter->second;
                }
            }

            int newDiff = n - 1 - A[i];
            ++rotatedMap[newDiff + i];
            if(newDiff >= 0)
            {
                ++localMaxScore;
            }

            lastScore = localMaxScore;

            if(localMaxScore > maxScore)
            {
                maxScore = localMaxScore;
                bestRotate = i + 1;
            }
        }

        return bestRotate;
    }
};

int main() {
    Solution s;
    vector<int> a{2, 3, 1, 4, 0};
    //vector<int> a{1, 3, 0, 2, 4};
    std::cout<<s.bestRotation(a)<<std::endl;
}
