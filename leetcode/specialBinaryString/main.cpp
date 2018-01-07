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
    string makeLargestSpecial(string S) {
        int n = S.size();
        while(improve(S, n)){}
        return S;
    }

private:
    bool improve(string& S, int n)
    {
        //std::cout<<S<<std::endl;
        string maxS = S;
        bool improved = false;
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == '1')
            {
                for(int j = 2; j <= n - i; j += 2)
                {
                    const auto& sub = S.substr(i, j);
                    if(isSpecial(sub))
                    {
                        //std::cout<<"sub "<<sub<<" "<<i<<" "<<j<<std::endl;
                        if(S[i + j] == '1')
                        {
                            for(int k = 2; k <= n - i - j; k += 2)
                            {
                                const auto& sub2 = S.substr(i + j, k);
                                if(isSpecial(sub2))
                                {
                                    //std::cout<<"sub2 "<<sub2<<std::endl;
                                    string temp = S.substr(0, i) + sub2 + sub + S.substr(i + j + k);
                                    //std::cout<<"temp "<<temp<<std::endl;
                                    if(temp > maxS)
                                    {
                                        maxS = temp;
                                        improved = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if(improved)
        {
            S = maxS;
            return true;
        }

        return false;
    }
    bool isSpecial(const string& s)
    {
        int n = s.size();
        int zeroCount = 0;
        for(int i = 0; i < n ; ++i)
        {
            if(s[i] == '0')
            {
                ++zeroCount;
                if(zeroCount > (i + 1) / 2)
                {
                    return false;
                }
            }
        }

        return zeroCount * 2 == n;
    }
};

int main()
{
    Solution s;
    //string S = "11011000";
    //string S = "1010101100";
    string S = "101100101100";
    std::cout<<s.makeLargestSpecial(S)<<std::endl;;
}
