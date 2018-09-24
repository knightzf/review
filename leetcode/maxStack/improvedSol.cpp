#include "header.h"

class MaxStack {
private:
    set<pair<int, int>> stack;
    set<pair<int, int>> valMap;
    int cnt = 0;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stack.emplace(make_pair(++cnt, x));
        valMap.emplace(make_pair(x, cnt));
    }
    
    int pop() {
        int t = stack.rbegin()->second;
        int n = stack.rbegin()->first;
        stack.erase(make_pair(n, t));
        valMap.erase(make_pair(t, n));
        return t;
    }
    
    int top() {
        return stack.rbegin()->second;
    }
    
    int peekMax() {
        return valMap.rbegin()->first;
    }
    
    int popMax() {
        int t = peekMax();
        int n = valMap.rbegin()->second;
        stack.erase(make_pair(n, t));
        valMap.erase(make_pair(t, n));
        return t;
    }
};

int main() {
    //Solution s;
}
