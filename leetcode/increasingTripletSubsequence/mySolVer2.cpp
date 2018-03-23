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
    bool increasingTriplet(vector<int>& nums) {
        vector<int> t;
        for(int n : nums)
        {
            if(t.empty() || n > t.back())
            {
                t.push_back(n);
                if(t.size() == 3) return true;
            }
            else
            {
                for(int i = 0; i < t.size(); ++i)
                {
                    if(n <= t[i])
                    {
                        t[i] = n;
                        break;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
}
