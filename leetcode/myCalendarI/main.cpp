#include "header.h"

class MyCalendar {
private:
    map<int, int> m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto iter = m.lower_bound(start);
        if(iter == m.end())
        {
            m.emplace(end, start);
            return true;
        }
        else
        {
            if(start == iter->first)
            {
                ++iter;
                if(iter == m.end() || end <= iter->second)
                {
                    m.emplace(end, start);
                    return true;
                }
                return false;
            }
            else
            {
                if(start < iter->second && end <= iter->second)
                {
                    m.emplace(end, start);
                    return true;
                }
                return false;
            }            
        }        
    }
};


int main()
{
}