#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
        std::unordered_set<int> m;
        int n = s.size();
        for(int i = 0; i < n - 1; ++i)
        {
            if(s[i] == '+' && s[i + 1] == '+')
                m.insert(i);
        }

        return willWin(m);
    }

    bool willWin(std::unordered_set<int>& m)
    {
        /*std::cout<<"--";
        for(auto i : m)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        std::vector<int> v(m.begin(), m.end());
        for(auto i : v)
        {
            m.erase(i);
            bool removeNext = false;
            if(m.find(i + 1) != m.end())
            {
                removeNext = true;
                m.erase(i + 1);
            }
            bool removePre = false;
            if(m.find(i - 1) != m.end())
            {
                removePre = true;
                m.erase(i - 1);
            }

            bool t = willWin(m);

            m.insert(i);
            if(removeNext) m.insert(i + 1);
            if(removePre) m.insert(i - 1);

            if(!t) return true;
        }

        return false;
    }
};

class Solution1 {
public:
int len;
string ss;
bool canWin(string s) {
    len = s.size();
    ss = s;
    return canWin();
}
bool canWin() {
    for (int is = 0; is <= len-2; ++is) {
        if (ss[is] == '+' && ss[is+1] == '+') {
            ss[is] = '-'; ss[is+1] = '-';
            bool wins = !canWin();
            ss[is] = '+'; ss[is+1] = '+';
            if (wins) return true;
        }
    }
    return false;
}
};

int main() {
    Solution s;
    std::cout<<s.canWin("++++")<<std::endl;
    std::cout<<s.canWin("+++++")<<std::endl;
    std::cout<<s.canWin("++++-++++++")<<std::endl;
    Solution1 s1;
    std::cout<<s1.canWin("+++++++++")<<std::endl;
}
