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
#include <iterator>

using namespace std;


void parseInts(const std::string& s, vector<int>& v)
{
    std::istringstream iss(s);
    std::copy(istream_iterator<int>(iss),
        istream_iterator<int>(),
        back_inserter(v));
}

int knapSack1(int maxW, const std::vector<int>& valVec, const std::vector<int>& weightVec, int n)
{
    vector<int> dp(maxW + 1, 0);

    for(int i = 0; i <= maxW; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(weightVec[j] <= i)
            {
                dp[i] = std::max(dp[i], dp[i - weightVec[j]] + valVec[j]);
            }
        }
    }

    return dp[maxW];
}

int knapSack(int maxW, const std::vector<int>& valVec, const std::vector<int>& weightVec, int n)
{
    if(maxW == 0 || n == 0) return 0;

    int maxValue = 0;

    int count = 0;
    while(weightVec[n - 1] * count <= maxW)
    {
        maxValue = std::max(maxValue,
                            valVec[n - 1] * count +
                            knapSack(maxW - weightVec[n - 1] * count, valVec, weightVec, n - 1));
        ++count;
    }

    return maxValue;
}

int main() {
    string t;
    std::getline(std::cin, t);
    int numTests = std::stoi(t);

	for(int i = 0; i < numTests; ++i)
	{
	    std::getline(std::cin, t);
	    int n = std::stoi(t);

	    std::getline(std::cin, t);
	    int maxWeight = std::stoi(t);

	    std::string vals;
	    std::getline(std::cin, vals);
	    std::vector<int> valVec;
	    parseInts(vals, valVec);

	    std::string weightStr;
	    std::getline(std::cin, weightStr);
	    std::vector<int> weightVec;
	    parseInts(weightStr, weightVec);

	    std::cout<<knapSack(maxWeight, valVec, weightVec, n)<<std::endl;
	}
	return 0;
}
