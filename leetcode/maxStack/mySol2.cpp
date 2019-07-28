#include "header.h"

class MaxStack {
private:
    map<int, vector<list<int>::iterator>> m;
    list<int> l;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        l.push_front(x);
        m[x].push_back(l.begin());
    }

    int pop() {
        int res = top();
        auto iter = m.find(l.front());
        if(iter->second.size() > 1) iter->second.pop_back();
        else m.erase(iter);
        l.pop_front();
        return res;
    }

    int top() {
        return l.front();
    }

    int peekMax() {
        return m.rbegin()->first;
    }

    int popMax() {
        int res = peekMax();
        l.erase(m.rbegin()->second.back());
        auto iter = m.find(res);
        if(iter->second.size() > 1) iter->second.pop_back();
        else m.erase(iter);
        return res;
    }
};

int main()
{
    //Solution s;
}