#include "header.h"

class Solution {
private:
    int n;
    unordered_set<int> s;
public:
    Solution(int N, vector<int> blacklist) {
        n = N;
        s.insert(blacklist.begin(), blacklist.end());
    }
    
    int pick() {
        int t = rand() % n;
        while(s.count(t)) {
            t = rand() % n;
        }
        return t;
    }
};

int main() {
    //Solution s;
}
