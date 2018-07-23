#include "header.h"

class StringIterator {
private:
    stringstream ss;
    char c;
    int cnt;
public:
    StringIterator(string compressedString) {
        ss.clear();
        ss << compressedString;
        cnt = 0;
    }

    char next() {
        while(cnt == 0 && !ss.eof())
        {
            ss >> c >> cnt;
        }
        if(cnt > 0)
        {
            --cnt;
            return c;
        }
        return ' ';
    }

    bool hasNext() {
        return cnt != 0 || !ss.eof();
    }
};


int main() {
    //Solution s;
    StringIterator s("L1e2");
    //StringIterator s("L1e2t1C1o1d1e1");

}
