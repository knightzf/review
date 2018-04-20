#include "header.h"

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size() - 1);
        return m[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = m.find(val);
        if(iter != m.end() && !iter->second.empty())
        {
            int idx = *iter->second.begin();
            iter->second.erase(idx);
            if(idx != v.size() - 1)
            {
                v[idx] = v.back();
                m[v.back()].erase(v.size() - 1);
                m[v.back()].insert(idx);
            }
            v.pop_back();
            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        if(v.empty()) return -1;
        return v[rand() % v.size()];
    }
};

int main()
{
    //Solution s;
}
