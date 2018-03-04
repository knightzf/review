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
    int preimageSizeFZF(int K) {
        //std::cout<<count(5)<<" "<<count(4)<<std::endl;
        return count(K) - count(K-1);
    }

    int count(int n)
    {
        int low = 0, high = 1e9;
        while(low <= high)
        {
            //std::cout<<low<<" "<<high<<std::endl;
            int mid = (low + high) / 2;
            int t = getZeros(mid);
            if(t > n)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low - 1;
    }

    int getZeros(int N)
    {
        int res = 0;
        for(int i = 5; N / i >= 1; i *= 5)
        {
            res += N / i;
        }
        return res;
    }
};


int main() {
    Solution s;
    std::cout<<s.preimageSizeFZF(5)<<std::endl;
    //std::cout<<s.preimageSizeFZF(80502705)<<std::endl;
}
