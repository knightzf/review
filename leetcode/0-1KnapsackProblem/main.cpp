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

	    std::vector<std::unordered_set<int>> packs(n);
	    std::vector<int> maxValues(n, 0);
	    std::vector<int> totalWeights(n, 0);

	    for(int i = 0; i < n; ++i)
	    {
	        int localMaxValue = 0;
	        int localtotalWeight = 0;
	        std::unordered_set<int> packSet;

	        if(weightVec[i] <= maxWeight)
	        {
	            localMaxValue = valVec[i];
	            localtotalWeight = weightVec[i];
	            packSet.insert(i);
	        }

	        for(int j = 0; j < i; ++j)
            {
                if(maxValues[j] > 0)
                {
                    if(totalWeights[j] + weightVec[i] <= maxWeight)
                    {
                        if(maxValues[j] + valVec[i] > localMaxValue)
                        {
                            localtotalWeight = totalWeights[j] + weightVec[i];
                            localMaxValue = maxValues[j] + valVec[i];
                            packSet = packs[j];
                            packSet.insert(i);
                        }
                    }
                    else
                    {
                        for(int id : packs[j])
                        {
                            if(totalWeights[j] - weightVec[id] + weightVec[i] <= maxWeight)
                            {
                                if(maxValues[j] - valVec[id] + valVec[i] > localMaxValue)
                                {
                                    localtotalWeight = totalWeights[j] - weightVec[id] + weightVec[i];
                                    localMaxValue = maxValues[j] - valVec[id] + valVec[i];
                                    packSet = packs[j];
                                    packSet.erase(id);
                                    packSet.insert(i);
                                }
                            }
                        }
                    }
                }
            }

            packs[i] = packSet;
            maxValues[i] = localMaxValue;
            totalWeights[i] = localtotalWeight;
	    }

	    std::cout<<*std::max_element(maxValues.begin(), maxValues.end())<<std::endl;
	}
	return 0;
}
