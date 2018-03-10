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

class HitCounter {
private:
    std::queue<std::pair<int, int>> q;
    int totalHits = 0;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if(q.empty() || q.back().first < timestamp) q.push(std::make_pair(timestamp, 1));
        else ++q.back().second;
        ++totalHits;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty() && q.front().first <= timestamp - 300)
        {
            totalHits -= q.front().second;
            q.pop();
        }

        return totalHits;
    }
};


int main() {
    //Solution s;
}
