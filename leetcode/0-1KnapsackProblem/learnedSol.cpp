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

int knapSack(int maxW, const std::vector<int>& valVec, const std::vector<int>& weightVec, int n)
{
    if (n == 0 || maxW == 0)
       return 0;

    if(weightVec[n - 1] > maxW)
    {
        return knapSack(maxW, valVec, weightVec, n - 1);
    }
    else
    {
        return std::max(valVec[n - 1] + knapSack(maxW - weightVec[n - 1], valVec, weightVec, n - 1),
                 knapSack(maxW, valVec, weightVec, n - 1));
    }
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
