#include "header.h"

class RandomizedCollection {
private:
    unordered_map<int, list<int>> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = m[val].size() == 0;
        v.push_back(val);
        m[val].push_back(v.size() - 1);
        return res;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.empty() || m[val].empty()) return false;
        int idx = m[val].back();
        m[v.back()].push_front(idx);
        m[v.back()].pop_back();
        v[idx] = v.back();
        v.pop_back();
        m[val].pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

int main()
{
    //Solution s;
}