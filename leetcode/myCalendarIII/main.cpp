#include "header.h"

class MyCalendarThree {
private:
    map<int, int> m;
    int k;
public:
    MyCalendarThree() {
        k = 1;
    }
    
    int book(int start, int end) {
        int prevCount = 0;
        auto iter = m.upper_bound(start);
        if(iter != m.begin())
        {
            --iter;
            prevCount = iter->second;
            ++iter;
        }

        ++prevCount;
        k = max(k, prevCount);
        m[start] = prevCount;
        for(iter = m.upper_bound(start); iter != m.end() && iter->first < end; ++iter)
        {
            ++iter->second;
            prevCount = iter->second;
            k = max(k, prevCount);
        }
        if(!m.count(end)) m[end] = prevCount - 1;

        return k;
    }
};


int main()
{
    //Solution s;
}