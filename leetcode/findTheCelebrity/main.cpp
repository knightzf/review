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

bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        std::vector<int> knowsNobodyV;
        for(int i = 0; i < n; ++i)
        {
            bool knowsNobody = true;
            for(int j = 0; j < n; ++j)
            {
                if(j != i && knows(i, j))
                {
                    knowsNobody = false;
                    break;
                }
            }

            if(knowsNobody)
            {
                knowsNobodyV.push_back(i);
            }
        }

        for(int i = 0; i < knowsNobodyV.size(); ++i)
        {
            int id = knowsNobodyV[i];
            bool isCelebrity = true;
            for(int j = 0; i < n; ++j)
            {
                if(j != id && !knows(j, id))
                {
                    isCelebrity = false;
                    break;
                }
            }

            if(isCelebrity) return id;
        }

        return -1;
    }
};

int main() {
    Solution s;
}
