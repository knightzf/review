#include "header.h"

class RandomizedSet {
private:
    unordered_map<int, int> s;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) == s.end())
        {
            v.push_back(val);
            s[val] = v.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) != s.end())
        {
            if(v.back() == val)
                v.pop_back();
            else
            {
                int valIdx = s[val];
                s[v.back()] = valIdx;
                v[valIdx] = v.back();
                v.pop_back();
            }
            s.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % s.size();
        return v[r];
    }
};

int main()
{
    //Solution s;
}
