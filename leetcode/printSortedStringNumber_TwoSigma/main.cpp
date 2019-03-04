#include "header.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    vector<string> strings;
    vector<int> numbers;
    vector<bool> tokenTypes;

    size_t startIdx = 0;
    for (size_t i = 0, sz = input.size(); i <= sz; ++i) {
      if (i == sz || input[i] == ' ') {
        const string &token = input.substr(startIdx, i - startIdx);
        cout<<token<<endl;
        if (isalpha(token[0])) {
          strings.emplace_back(token);
          tokenTypes.emplace_back(true);
        } else {
          numbers.emplace_back(stoi(token));
          tokenTypes.emplace_back(false);
        }
        startIdx = i + 1;
      }
    }

    sort(strings.begin(), strings.end());
    sort(numbers.begin(), numbers.end());

    stringstream res;
    for(size_t i = 0, j = 0, k = 0, sz = tokenTypes.size(); i < sz; ++i)
    {
        if(i != 0) 
        {
            res << " ";
        }

        if(tokenTypes[i])
        {
            res << strings[j++];
        }
        else
        {
            res << numbers[k++];
        }
    }

    cout<<res.str()<<endl;
    return 0;
}



/*int main()
{
    //Solution s;
}*/