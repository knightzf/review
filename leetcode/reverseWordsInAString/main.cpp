#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();

        if(n == 0) return;

        int count = 0;
        int insertIdx = 0;

        while(count < n)
        {
            std::string temp;
            bool foundSpace = false;
            while(!foundSpace && count < n)
            {
                if(s.back() != ' ')
                    temp += s.back();
                else
                    foundSpace = true;

                s.pop_back();
                ++count;

                if(foundSpace) break;
            }
            std::reverse(temp.begin(), temp.end());
            //std::cout<<temp<<std::endl;

            if(!temp.empty())
            {
                s.insert(insertIdx, (insertIdx == 0 ? "" : " ") + temp);
                insertIdx += temp.size() + (insertIdx == 0 ? 0 : 1);
            }
            //std::cout<<"s "<<s<<std::endl;
            //std::cout<<"idx "<<insertIdx<<std::endl;
        }
    }
};


int main()
{
    Solution s;

    std::string a = "the sky is blue";
    s.reverseWords(a);
    std::cout<<a<<"<<"<<std::endl;
    std::string b = "    a    ";
    s.reverseWords(b);
    std::cout<<b<<"<<"<<std::endl;
    std::string c = " ";
    s.reverseWords(c);
    std::cout<<c<<"<<"<<std::endl;

}
