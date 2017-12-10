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

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        bool hasLarger = false;
        char smallest;
        char smallestLarger;

        for(int i = 0; i < letters.size(); ++i)
        {
            if(i == 0)
            {
                smallest = letters[i];
                if(letters[i] > target)
                {
                    smallestLarger = letters[i];
                    hasLarger = true;
                }
            }
            else
            {
                smallest = letters[i] < smallest ? letters[i] : smallest;

                if(letters[i] > target)
                {
                    if(hasLarger)
                    {
                        smallestLarger = letters[i] < smallestLarger ? letters[i] : smallestLarger;
                    }
                    else
                    {
                        smallestLarger = letters[i];
                        hasLarger = true;
                    }
                }
            }
        }

        if(hasLarger)
        {
            return smallestLarger;
        }

        return smallest;
    }
};

int main()
{
    Solution s;
    vector<char> a{'c', 'f', 'j'};
    std::cout<<s.nextGreatestLetter(a, 'k')<<std::endl;
}
