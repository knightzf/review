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

using namespace std;

class Solution {
public:
    int count(int v, int m, int n)
    {
        int count = 0;

        for(int i = 1; i <= m; ++i)
        {
            count += std::min(v/i, n);
        }

        return count;
    }

    int findKthNumber(int m, int n, int k)
    {
        int low = 1;
        int high = m * n + 1;

        while(low < high)
        {
            int mid = low + (high - low) / 2;
            int c = count(mid, m, n);
            //std::cout<<low<<" "<<high<<" "<<mid<<" "<<c<<std::endl;
            if(c >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
            //std::cout<<low<<" "<<high<<std::endl;
        }

        return high;
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.findKthNumber(3, 3, 5)<<std::endl;
    return 0;
}
