#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
int main() {
    int numDC = 0;
    unordered_map<int, unordered_set<int>> dataToDCMap;
    string x;
    getline(cin, x);
    //cin >> numDC;
    numDC = stoi(x);
    for(int i = 0; i < numDC; ++i)
    {
        int dc = i + 1;
        string detail;
        getline(cin, detail);

        size_t startIdx = 0;
        for(size_t j = 0, sz = detail.size(); j <= sz; ++j)
        {
            if(j == sz || detail[j] == ' ')
            {
                int data = stoi(detail.substr(startIdx, j - startIdx));
                if(startIdx != 0)
                {
                    dataToDCMap[data].insert(dc);
                }
                startIdx = j + 1;
            }
        }
    }

    for(const auto& p : dataToDCMap)
    {
        for(int dc = 1; dc <= numDC; ++dc)
        {
            if(p.second.find(dc) == p.second.end())
            {
                cout<< p.first << *p.second.begin() << dc << endl;
            }
        }
    }
    cout<<"done"<<endl;
    
    return 0;
}

