#include "header.h"

class MyCalendarTwo {
private:
    map<int, int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int prevCount = 0;
        auto iter = m.upper_bound(start);
        if(iter != m.begin())
        {
            --iter;
            prevCount = iter->second;
            ++iter;
        }

        if(prevCount + 1 > 2) return false;
        for(; iter != m.end() && iter->first < end; ++iter)
        {
            if(iter->second + 1 > 2) return false;
        }

        ++prevCount;
        m[start] = prevCount;
        for(iter = m.upper_bound(start); iter != m.end() && iter->first < end; ++iter)
        {
            ++iter->second;
            prevCount = iter->second;
        }
        if(!m.count(end)) m[end] = prevCount - 1;

        return true;
    }
};

int main()
{
    //Solution s;
    MyCalendarTwo c;
    c.book(10, 20);
    c.book(50, 60);
    c.book(10, 40);
    c.book(5, 15);
    c.book(5, 10);
}