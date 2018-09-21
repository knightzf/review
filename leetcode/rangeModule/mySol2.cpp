#include "header.h"

class RangeModule {
    map<int, int> m;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto iter = m.lower_bound(left);
        if(iter != m.end())
        {
            if(iter->second == 1)
            {
                while(iter != m.end())
                {
                    if(iter->first <= right)
                    {
                        iter = m.erase(iter);
                    }
                    else 
                    {
                        if(iter->second == -1)
                        {
                            right = iter->first;
                            iter = m.erase(iter);
                        }                      
                        break;
                    }
                }
                m.emplace(left, 1);
                m.emplace(right, -1);
            }
            else
            {
                if(iter->first <= right)
                {
                    --iter;
                    auto t = iter->first;
                    ++iter;
                    m.erase(iter);
                    addRange(t, right);
                }
            }
        }
        else
        {
            m.emplace(left, 1);
            m.emplace(right, -1);
        }
    }
    
    bool queryRange(int left, int right) {
        auto iter = m.lower_bound(right);
        if(iter != m.end() && iter->second == -1)
        {
            --iter;
            return iter->first <= left;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        auto iter = m.lower_bound(left);
        if(iter != m.end())
        {
            if(iter->second == -1)
            {
                if(iter->first == left) ++iter;
                else m.emplace(left, -1);
            } 

            while(iter != m.end())
            {
                if(iter->first <= right)
                {
                    iter = m.erase(iter);
                }
                else
                {
                    if(iter->second == -1)
                    {
                        m.emplace(right, 1);
                    }
                    break;
                }
            }
        }        
    }
};


int main() {
    //Solution s;
    RangeModule r;
    r.addRange(2, 8);
    r.removeRange(7, 9);
}
