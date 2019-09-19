#include "header.h"

class MyCalendarTwo {
private:
    map<int, int> m;
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        ++m[start], --m[end];
        int cnt = 0;
        for(auto& p : m) {
            cnt += p.second;
            if(cnt == 3) {
                --m[start], ++m[end];
                return false;
            }
        }
        return true;
    }
};

int main()
{
    //Solution s;
}