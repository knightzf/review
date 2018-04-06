#include "header.h"

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    using Iterator = vector<NestedInteger>::const_iterator;
    stack<pair<Iterator, Iterator>> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(make_pair(nestedList.cbegin(), nestedList.cend()));
    }

    int next() {
        //hasNext();
        return (s.top().first++)->getInteger();
    }

    bool hasNext() {
        while(!s.empty())
        {
            if(s.top().first == s.top().second)
                s.pop();
            else
            {
                auto iter = s.top().first;
                if(iter->isInteger())
                    return true;

                ++s.top().first;
                s.push(make_pair(iter->getList().cbegin(), iter->getList().cend()));
            }
        }

        return false;
    }
};

int main()
{
    //Solution s;
}
