#include "header.h"

class MinStack {
private:
    stack<int> m_s;
    int m_min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(x <= m_min) {
            m_s.push(m_min);
            m_min = x;
        }
        m_s.push(x);
    }
    
    void pop() {
        if(m_s.top() == m_min) {
            m_s.pop();
            m_min = m_s.top();
        }
        m_s.pop();
    }
    
    int top() {
        return m_s.top();
    }
    
    int getMin() {
        return m_min;
    }
};

int main()
{
    //Solution s;    
}