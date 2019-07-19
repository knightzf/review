#include "header.h"

class AllOne {
private:
    struct Count{ int cnt; unordered_set<string> keys; };
    list<Count> lst;
    using Iter = list<Count>::iterator;
    unordered_map<string, Iter> m;
public:
    AllOne() {}

    void inc(string key) {
        if(!m.count(key)) {
            lst.insert(lst.begin(), Count{0, {}});
            m[key] = lst.begin();
        }
        auto iter = m[key];
        auto next = iter; ++next;
        if(next == lst.end() || next->cnt > iter->cnt + 1) {
            m[key] = lst.insert(next, Count{iter->cnt + 1, {key}});
        } else {
            next->keys.insert(key);
            m[key] = next;
        }
        iter->keys.erase(key);
        if(iter->keys.empty()) lst.erase(iter);
    }

    void dec(string key) {
        if(!m.count(key)) return;
        auto iter = m[key];
        auto pre = iter; --pre;
        if(iter == lst.begin() || pre->cnt < iter->cnt - 1) {
            if(iter->cnt > 1) m[key] = lst.insert(iter, Count{iter->cnt - 1, {key}});
            else m.erase(key);
        } else {
            pre->keys.insert(key);
            m[key] = pre;
        }
        iter->keys.erase(key);
        if(iter->keys.empty()) lst.erase(iter);
    }

    string getMaxKey() {
        if(lst.empty()) return "";
        return *lst.back().keys.begin();
    }

    string getMinKey() {
        if(lst.empty()) return "";
        return *lst.front().keys.begin();
    }
};


int main()
{
    //Solution s;
}