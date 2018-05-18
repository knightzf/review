#include "header.h"

class LFUCache {
private:
    using CountKeyList = list<pair<int, list<int>>>;

    struct Value
    {
        int value;
        CountKeyList::iterator countIter;
        list<int>::iterator keyIter;
    };

    int n;
    CountKeyList l;
    unordered_map<int, Value> m;

public:
    LFUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        if(m.find(key) == m.end())
            return -1;

        auto& v = m[key];

        int cnt = v.countIter->first + 1;
        v.countIter->second.erase(v.keyIter);

        auto tter = v.countIter;
        auto iter = v.countIter;
        ++iter;
        if(iter == l.end() || iter->first != cnt)
        {
            v.countIter = l.insert(iter, make_pair(cnt, list<int>{key}));
            v.keyIter = v.countIter->second.begin();
        }
        else
        {
            iter->second.push_front(key);
            v.countIter = iter;
            v.keyIter = iter->second.begin();
        }

        if(tter->second.empty())
        {
            l.erase(tter);
        }

        return v.value;
    }

    void put(int key, int value) {
        if(n == 0) return;

        if(m.find(key) != m.end())
        {
            auto& v = m[key];
            int cnt = v.countIter->first + 1;
            v.countIter->second.erase(v.keyIter);
            v.value = value;

            auto tter = v.countIter;
            auto iter = v.countIter;
            ++iter;
            if(iter == l.end() || iter->first != cnt)
            {
                v.countIter = l.insert(iter, make_pair(cnt, list<int>{key}));
                v.keyIter = v.countIter->second.begin();
            }
            else
            {
                iter->second.push_front(key);
                v.countIter = iter;
                v.keyIter = iter->second.begin();
            }

            if(tter->second.empty())
            {
                l.erase(tter);
            }
        }
        else
        {
            if(m.size() == n)
            {
                int tkey = l.begin()->second.back();
                l.begin()->second.pop_back();
                if(l.begin()->second.empty())
                    l.pop_front();
                m.erase(tkey);
            }

            if(l.begin()->first == 1)
                l.begin()->second.push_front(key);
            else
                l.push_front(make_pair(1, list<int>{key}));

            Value v;
            v.value = value;
            v.countIter = l.begin();
            v.keyIter = l.begin()->second.begin();
            m[key] = v;
        }
    }
};

int main()
{
    //Solution s;
    LFUCache c(1);
    c.put(2, 1);
    cout<<c.get(2)<<endl;
    c.put(3, 2);
    cout<<c.get(2)<<endl;
    cout<<c.get(3)<<endl;
}
