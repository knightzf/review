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

using namespace std;

class Solution {
public:
    void addParenthesis(std::string s, int leftRemain, int rightRemain)
    {
        std::cout<<s<<" "<<leftRemain<<" "<<rightRemain<<std::endl;
        if(leftRemain == 0 && rightRemain == 0)
        {
            result.push_back(s);
            return;
        }

        if(leftRemain > 0)
        {
            addParenthesis(s + "(", leftRemain - 1, rightRemain);
        }

        if(leftRemain < rightRemain)
        {
            addParenthesis(s + ")", leftRemain, rightRemain - 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        result.clear();

        if(!n)
        {
            return result;
        }

        addParenthesis("", n, n);
        return result;
    }

private:
    std::vector<string> result;
};

int main()
{
    Solution sol;
    const auto & a = sol.generateParenthesis(3);
    for(const auto& i : a)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}
