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

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(std::make_pair(v1.begin(), v1.end()));
        v.push_back(std::make_pair(v2.begin(), v2.end()));
        rowCount = 2;
        colCount = std::max(v1.size(), v2.size());
    }

    int next() {
        int r = *(v[row].first + col);

        if(row == 0) ++row;
        else
        {
            ++col;
            row = 0;
        }

        return r;
    }

    bool hasNext() {
        //std::cout<<col<<" "<<colCount<<" "<<row<<" "<<rowCount<<std::endl;
        for(int i = col; i < colCount; ++i)
        {
            for(int j = row; j < rowCount; ++j)
            {
                if(v[j].first + i < v[j].second)
                {
                    row = j;
                    col = i;
                    return true;
                }
            }
            row = 0;
        }

        return false;
    }

    int nextRow(int i)
    {
        if(i == 0) return 1;
        return 0;
    }

private:
    std::vector<std::pair<vector<int>::iterator, vector<int>::iterator>> v;
    int row = 0;
    int col = 0;
    int rowCount;
    int colCount;
};

int main() {
    //Solution s;
    vector<int> a{1, 2};
    //vector<int> b{3, 4, 5, 6};
    vector<int> b{};
    ZigzagIterator c(a, b);
    while(c.hasNext())
    {
        std::cout<<c.next()<<std::endl;
    }
}
