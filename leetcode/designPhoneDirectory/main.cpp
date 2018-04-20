#include "header.h"

class PhoneDirectory {
private:
    unordered_set<int> available;
    unordered_set<int> used;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; ++i)
            available.insert(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(available.empty()) return -1;
        int r = *available.begin();
        available.erase(available.begin());
        used.insert(r);
        return r;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return available.find(number) != available.end();
    }

    /** Recycle or release a number. */
    void release(int number) {
        if(used.find(number) != used.end())
        {
            used.erase(number);
            available.insert(number);
        }
    }
};

int main()
{
    //Solution s;
}
