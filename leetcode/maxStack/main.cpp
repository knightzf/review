#include "header.h"

class MaxStack {
private:
    list<int> ls;
    using Iter = list<int>::iterator;
    map<int, vector<Iter>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        ls.push_front(x);
        m[x].push_back(ls.begin());
    }
    
    int pop() {
        int t = *ls.begin();
        m[t].pop_back();
        if(m[t].empty())
        {
            m.erase(t);
        }
        ls.pop_front();
        return t;
    }
    
    int top() {
        return *ls.begin();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int t = peekMax();
        ls.erase(m.rbegin()->second.back());
        m.rbegin()->second.pop_back();
        if(m.rbegin()->second.empty())
        {
            m.erase(t);
        }
        return t;
    }
};

int main() {
    //Solution s;
}
