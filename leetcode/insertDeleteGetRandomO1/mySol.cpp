#include "header.h"

class RandomizedSet {
private:
    unordered_set<int> s;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) == s.end())
        {
            s.insert(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) != s.end())
        {
            s.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % s.size();
        auto iter = s.begin();
        while(r)
        {
            ++iter;
            --r;
        }
        return *iter;
    }
};

int main()
{
    //Solution s;
}
