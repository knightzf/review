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

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        rowIter = vec2d.begin();
        rowEndIter = vec2d.end();

        if(rowIter != rowEndIter)
        {
            while(rowIter->empty() && rowIter != rowEndIter)
            {
                ++rowIter;
            }

            if(rowIter != rowEndIter)
            {
                colIter = rowIter->begin(); --colIter;
            }
        }
    }

    int next() {
        return *colIter;
    }

    bool hasNext() {
        if(rowIter == rowEndIter) return false;

        while(rowIter->empty() && rowIter != rowEndIter)
        {
            ++rowIter;
        }
        if(rowIter == rowEndIter) return false;

        auto p = rowIter->end();
        ++colIter;
        if(colIter == p)
        {
            ++rowIter;
            if(rowIter == rowEndIter) return false;

            while(rowIter->empty() && rowIter != rowEndIter)
            {
                ++rowIter;
            }
            if(rowIter == rowEndIter) return false;

            colIter = rowIter->begin();
        }

        return true;
    }
private:
    vector<vector<int>>::iterator rowIter;
    vector<vector<int>>::iterator rowEndIter;
    vector<int>::iterator colIter;
};


int main() {
    //Solution s;
}
