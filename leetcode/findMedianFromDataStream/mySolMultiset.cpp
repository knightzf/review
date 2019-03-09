#include "header.h"

class MedianFinder {
private:
    multiset<int> m_set;
    multiset<int>::iterator m_iter = m_set.end();
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        m_set.insert(num);

        if(m_iter == m_set.end()) m_iter = m_set.begin();
        else
        {
            int sz = m_set.size();
            if(sz % 2) 
            {
                
                if(num >= *m_iter) ++m_iter;
            }
            else
            {
                if(num < *m_iter) --m_iter;
            }            
        }
    }
    
    double findMedian() {
        int sz = m_set.size();
        if(sz % 2) return *m_iter;
        auto iter = m_iter;
        ++iter;
        return (*m_iter + *iter) / 2.0;
    }
};



int main()
{
    //Solution s;
    MedianFinder s;
    s.addNum(6);
    s.addNum(10);
    s.addNum(2);
    s.addNum(6);
    cout<<s.findMedian()<<endl;
}