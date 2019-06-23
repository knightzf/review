#include "header.h"

class ZigzagIterator {
private:
    map<int, vector<int>> m;
    int idx = 0;
    map<int, vector<int>>::iterator iter;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m[1] = v1;
        m[2] = v2;
        iter = m.begin();
    }

    int next() {
        int t = iter->second[idx];
        ++iter;
        hasNext();
        return t;
    }

    bool hasNext() {
        while(!m.empty()) {
            if(iter == m.end()) {
                iter = m.begin();
                ++idx;
            } else if(idx >= iter->second.size()) {
                iter = m.erase(iter);
            } else break;            
        }
        return iter != m.end();
    }
};

int main()
{
    //Solution s;
}