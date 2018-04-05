#include "header.h"

class LRUCache {
private:
    int cap;
    using List = std::list<std::pair<int, int>>;
    using Cache = std::unordered_map<int, List::iterator>;
    List lst;
    Cache cache;
public:
    LRUCache(int capacity) : cap(capacity) {

    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        auto iter = cache[key];
        lst.push_front(*iter);
        lst.erase(iter);
        return lst.front().second;
    }

    void put(int key, int value) {
        if(lst.size() == cap)
        {
            cache.erase(lst.back().first);
            lst.pop_back();
        }

        lst.push_front(std::make_pair(key, value));
        cache[key] = lst.begin();
    }
};

int main()
{
    //Solution s;
    LRUCache c(2);
    c.put(2, 1);
    c.put(1, 1);
    std::cout<<c.get(2)<<std::endl;
    c.put(4, 1);
    std::cout<<c.get(1)<<std::endl;
    std::cout<<c.get(2)<<std::endl;
}
