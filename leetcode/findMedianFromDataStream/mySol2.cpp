#include "header.h"

class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || num <= small.top()) small.push(num);
        else large.push(num);
        if(small.size() > large.size() + 1) {
            int t = small.top();
            small.pop();
            large.push(t);    
        }
        if(large.size() > small.size()) {
            int t = large.top();
            large.pop();
            small.push(t);    
        }
    }
    
    double findMedian() {
        if((small.size() + large.size()) & 1) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};


int main()
{
    //Solution s;
}