#include "header.h"

class Vector2D {
    const vector<vector<int>>& data;
    int i = 0, j = 0;
public:
    Vector2D(vector<vector<int>>& v) : data(v) {
        
    }
    
    int next() {
        hasNext();
        return data[i][j++];
    }
    
    bool hasNext() {
        while(i < data.size()) {
            if(j >= data[i].size()) {
                ++i; j = 0; continue;
            } else {
                ++j;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    //Solution s;
}