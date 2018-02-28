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
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if(n < 4) return false;

        bool converge = x[2] <= x[0];
        bool statusChanged = false;
        int diffWithGrandParent;
        for(int i = 3; i < n; ++i)
        {
            if(converge)
            {
                if(x[i] >= x[i - 2])
                {
                    return true;
                }
                else
                {
                    if(statusChanged)
                    {
                        statusChanged = false;
                        if(diffWithGrandParent > 0)
                        {
                            if(x[i] >= x[i - 2])
                            {
                                return true;
                            }
                        }
                        else
                        {
                            if(x[i] + x[i - 4] >= x[i - 2])
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            else
            {
                if(x[i] <= x[i - 2])
                {
                    converge = true;
                    if(i >= 2)
                    {
                        statusChanged = true;
                        if(i < 4)
                        {
                            diffWithGrandParent = x[i - 2] != x[i];
                        }
                        else
                        {
                            diffWithGrandParent = x[i - 2] - x[i] - x[i - 4];
                        }
                    }
                }
            }
        }

        return false;

    }
};


int main() {
    Solution s;
    vector<int> a{1,1,2,1,1};
    std::cout<<s.isSelfCrossing(a)<<std::endl;
}
