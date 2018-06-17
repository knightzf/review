#include "header.h"

class ExamRoom {
private:
    set<int> s;
    int n;
public:
    ExamRoom(int N) {
        n = N;
    }

    int seat() {
        if(s.empty())
        {
            s.insert(0);
            return 0;
        }

        int idx = -1;
        int dis = 0;
        if(s.count(0) == 0)
        {
            idx = 0;
            dis = *s.begin();
        }

        for(auto iter = s.begin(); iter != s.end(); ++iter)
        {
            auto jter = iter;
            ++jter;
            if(jter == s.end())
            {
                if(n - 1 - *s.rbegin() > dis)
                {
                    dis = n - 1 - *s.rbegin();
                    idx = n - 1;
                }
            }
            else
            {
                int t = (*jter - *iter) / 2;
                if(t > dis)
                {
                    dis = t;
                    idx = (*jter + *iter) / 2;
                }
            }
        }

        s.insert(idx);
        return idx;
    }

    void leave(int p) {
        s.erase(p);
    }
};

int main()
{
}
