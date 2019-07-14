#include "header.h"

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    using Iter = vector<NestedInteger>::iterator;
    vector<NestedInteger>& m_list;
    stack<pair<Iter, Iter>> m_stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) : m_list(nestedList) {
        m_stack.push(make_pair(nestedList.begin(), nestedList.end()));
    }

    int next() {
        int res = m_stack.top().first->getInteger();
        ++m_stack.top().first;
        return res;
    }

    bool hasNext() {
        while(!m_stack.empty()) {
            if(m_stack.top().first == m_stack.top().second) {
                m_stack.pop();
                if(!m_stack.empty()) ++m_stack.top().first;
                continue;
            }
            if(m_stack.top().first->isInteger()) break;
            auto& list = m_stack.top().first->getList();
            m_stack.push(make_pair(list.begin(), list.end()));
        }
        return !m_stack.empty();
    }
};

int main()
{
    //Solution s;
}