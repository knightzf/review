#include "header.h"

class AllOne {
private:
    using List = list<pair<int, unordered_set<string>>>;
    List l;
    unordered_map<string, List::iterator> m;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(l.empty())
        {
            l.push_front(make_pair(1, unordered_set<string>{key}));
            m[key] = l.begin();
            return;
        }

        if(m.find(key) == m.end())
        {
            if(l.front().first != 1)
            {
                l.push_front(make_pair(1, unordered_set<string>{key}));
            }
            else
            {
                l.front().second.insert(key);
            }
            m[key] = l.begin();
        }
        else
        {
            auto iter = m[key];
            auto jter = iter;
            ++iter;
            if(iter != l.end())
            {
                if(iter->first == m[key]->first + 1)
                {
                    m[key] = iter;
                    iter->second.insert(key);
                }
                else
                {
                    auto t = l.insert(iter, make_pair(m[key]->first + 1, unordered_set<string>{key}));
                    m[key] = t;
                }
            }
            else
            {
                l.push_back(make_pair(m[key]->first + 1, unordered_set<string>{key}));
                ++m[key];
            }

            //clean up previous iterator
            jter->second.erase(key);
            if(jter->second.empty())
            {
                l.erase(jter);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.find(key) == m.end()) return;
        auto iter = m[key];
        if(iter->first == 1)
        {
            m.erase(key);
            l.front().second.erase(key);
            if(l.front().second.empty()) l.pop_front();
            return;
        }

        int newCnt = iter->first - 1;
        if(iter == l.begin())
        {
            l.front().second.erase(key);
            if(l.front().second.empty()) l.erase(l.begin());
            l.push_front(make_pair(newCnt, unordered_set<string>{key}));
            m[key] = l.begin();
        }
        else
        {
            auto jter = iter;
            --iter;
            if(iter->first == newCnt)
            {
                iter->second.insert(key);
                m[key] = iter;
            }
            else
            {
                auto t = l.insert(m[key], make_pair(newCnt, unordered_set<string>{key}));
                m[key] = t;
            }

            //clean up
            jter->second.erase(key);
            if(jter->second.empty())
            {
                l.erase(jter);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(l.empty()) return "";
        return *(l.back().second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(l.empty()) return "";
        return *(l.front().second.begin());
    }
};

int main()
{
    //Solution s;
    AllOne a;
    a.inc("hello");
    a.inc("goodbye");
    a.inc("hello");
    std::cout<<"cc"<<std::endl;
    a.inc("hello");
    std::cout<<"11"<<std::endl;
    std::cout<<a.getMaxKey()<<std::endl;
    a.inc("leet");
    std::cout<<"22"<<std::endl;
    a.inc("code");
    a.inc("leet");
    a.dec("hello");
    std::cout<<"33"<<std::endl;
    a.inc("leet");
    a.inc("code");
    a.inc("code");
    std::cout<<a.getMaxKey()<<std::endl;
}
