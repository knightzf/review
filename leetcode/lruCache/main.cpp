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

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        maxCap = capacity;
        minLife = 0;
        maxLife = 0;
    }

    int get(int key) {
        if(keyLifeMap.find(key) != keyLifeMap.end())
        {
            ++maxLife;

            lifeKeyMap.erase(keyLifeMap[key]);
            lifeKeyMap[maxLife] = key;
            keyLifeMap[key] = maxLife;

            return keyValueMap[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        ++maxLife;

        if(keyLifeMap.find(key) != keyLifeMap.end())
        {
            lifeKeyMap.erase(keyLifeMap[key]);
            keyLifeMap.erase(key);
        }

        if(keyLifeMap.size() == maxCap)
        {
            while(lifeKeyMap.find(minLife) == lifeKeyMap.end())
            {
                ++minLife;
            }

            keyLifeMap.erase(lifeKeyMap[minLife]);
            lifeKeyMap.erase(minLife);

            ++minLife;
        }

        keyLifeMap[key] = maxLife;
        lifeKeyMap[maxLife] = key;
        keyValueMap[key] = value;
    }

private:
    int maxCap;
    int minLife;
    int maxLife;
    std::unordered_map<int, int> keyLifeMap;
    std::unordered_map<int, int> lifeKeyMap;
    std::unordered_map<int, int> keyValueMap;
};



int main()
{
    //Solution s;

    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);
    std::cout<<cache.get(1)<<std::endl;
    std::cout<<cache.get(2)<<std::endl;

}
