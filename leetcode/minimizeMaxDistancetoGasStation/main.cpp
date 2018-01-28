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
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        vector<int> v;
        for(int i = 0; i < n - 1; ++i)
        {
            v.push_back(stations[i + 1] - stations[i]);
        }

        double l = 1e-8;
        double h = 1e8;

        while(h - l > 1e-8)
        {
            double m = (l + h) / 2;
            int cnt = 0;
            for(int i = 0; i < n - 1; ++i)
            {
                cnt += std::ceil(v[i] / m) - 1;
            }

            if(cnt <= K)
            {
                h = m;
            }
            else
            {
                l = m;
            }
        }

        return h;
    }
};

int main() {
    Solution s;
    vector<int> a{10,19,25,27,56,63,70,87,96,97};
    std::cout<<s.minmaxGasDist(a, 3)<<std::endl;
    //vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //std::cout<<s.minmaxGasDist(a, 9)<<std::endl;
}
