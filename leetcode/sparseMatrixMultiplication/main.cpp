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
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;

        int mA = A.size();
        if(mA == 0) return res;
        int nA = A[0].size();
        if(nA == 0) return res;

        int mB = B.size();
        if(mB == 0) return res;
        int nB = B[0].size();
        if(nB == 0) return res;

        res = vector<vector<int>>(mA, vector<int>(nB, 0));

        std::unordered_map<int, std::unordered_map<int, int>> mapA;
        for(int i = 0; i < mA; ++i)
        {
            for(int j = 0; j < nA; ++j)
            {
                if(A[i][j])
                {
                    mapA[i].emplace(j, A[i][j]);
                }
            }
        }
        std::unordered_map<int, std::unordered_map<int, int>> mapB;
        for(int i = 0; i < mB; ++i)
        {
            for(int j = 0; j < nB; ++j)
            {
                if(B[i][j])
                {
                    mapB[j].emplace(i, B[i][j]);
                }
            }
        }

        for(auto i = mapA.begin(); i != mapA.end(); ++i)
        {
            const auto& row = i->second;
            for(auto j = mapB.begin(); j != mapB.end(); ++j)
            {
                int sum = 0;
                for(const auto& item : row)
                {
                    if(j->second.find(item.first) != j->second.end())
                    {
                        sum += item.second * j->second[item.first];
                    }
                }

                res[i->first][j->first] = sum;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
}
