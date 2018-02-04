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
    vector<string> addOperators(string num, int target) {
        _num = num;
        _target = target;
        _n = num.size();

        if(_n == 0) return vector<string>();

        vector<string> res;
        string s;
        parseAndCompute(res, s, 0, 0, 0);

        return res;
    }

    void parseAndCompute(vector<string>& res, const std::string& s,
                         int startIdx, long calcRes, long mulRes)
    {
        if(calcRes == _target && startIdx == _n)
        {
            res.push_back(s);
            return;
        }

        for(int i = startIdx; i < _n; ++i)
        {
            if(i != startIdx && _num[startIdx] == '0') break;
            const std::string& numStr = _num.substr(startIdx, i + 1 - startIdx);
            long val = std::stol(numStr);

            if(startIdx == 0)
            {
                parseAndCompute(res, s + numStr, i + 1, val, val);
            }
            else
            {
                parseAndCompute(res, s + '+' + numStr, i + 1, calcRes + val, val);
                parseAndCompute(res, s + '-' + numStr, i + 1, calcRes - val, -val);
                parseAndCompute(res, s + '*' + numStr, i + 1, calcRes - mulRes + mulRes * val, mulRes * val);
            }

        }
    }

private:
    std::string _num;
    int _target;
    int _n;
};

int main() {
    Solution s;
    //const auto& r = s.addOperators("105", 5);
    const auto& r = s.addOperators("3456237490", 9191);
    for(auto i : r)
    {
        std::cout<<i<<std::endl;
    }
}
