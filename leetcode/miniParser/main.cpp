#include "header.h"

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        return impl(s, 0, s.size());
    }

    NestedInteger impl(const std::string& s, int startIdx, int endIdx)
    {
        if(s[startIdx] != '[')
        {
            return NestedInteger(std::stoi(s.substr(startIdx, endIdx - startIdx)));
        }

        NestedInteger t;
        for(int i = startIdx + 1; i < endIdx;)
        {
            if(s[i] == '[')
            {
                int j = i;
                int cnt = 1;
                while(j < endIdx && cnt)
                {
                    if(s[j] == '[') ++cnt;
                    else if(s[j] == ']') --cnt;
                    ++j;
                }
                t.add(impl(s, i, j));
                i = j + 1;
            }
            else if(s[i] == ']')
            {
                return t;
            }
            else
            {
                int j = i;
                while(j < endIdx && s[j] != ',') ++j;
                t.add(impl(s, i, j));
                i = j + 1;
            }
        }
        return t;
    }
};

int main()
{
    //Solution s;
}
