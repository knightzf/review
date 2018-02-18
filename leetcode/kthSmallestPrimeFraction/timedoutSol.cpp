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

bool cmp(const std::pair<double, std::vector<int>> &a, const std::pair<double, std::vector<int>> &b)
{
    return a.first < b.first;
}

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        std::vector<std::pair<double, std::vector<int>>> v;
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < A.size(); ++j)
            {
                if(A[i] < A[j])
                {
                    std::cout<<(double)A[i]/A[j]<<std::endl;
                    v.push_back(std::make_pair((double)A[i]/A[j], std::vector<int>{A[i], A[j]}));
                }
            }
        }

        std::nth_element(v.begin(), v.begin() + K - 1, v.end(), cmp);

        return v[K - 1].second;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 2, 3, 5};
    std::cout<<s.kthSmallestPrimeFraction(a, 3)[1]<<std::endl;
}
