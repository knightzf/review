#include "header.h"

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> s;
        int size = 0;
        for(int i = 0; i < n; ++i)
        {
            int t = asteroids[i];
            if(t < 0) {
                while(true)
                {
                    if(size == 0 || s[size - 1] < 0) {
                        if(s.size() >= size + 1) s[size] = t;
                        else s.push_back(t);
                        ++size;
                        break;
                    }
                    else if(s[size - 1] < -t) {
                        --size;
                    }
                    else if(s[size - 1] == -t) {
                        --size;
                        break;
                    }
                    else break;
                }
            }
            else {
                if(s.size() >= size + 1) s[size] = t;
                else s.push_back(t);
                ++size;
            }
        }
        s.resize(size);
        return s;
    }
};


int main()
{
    //Solution s;
}