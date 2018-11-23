#include "header.h"

class RecentCounter {
    deque<int> q; 
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push_back(t);
        while(!q.empty() && q.front() < t - 3000) q.pop_front();
        return q.size();
    }
};

int main()
{
    //Solution s;
}
