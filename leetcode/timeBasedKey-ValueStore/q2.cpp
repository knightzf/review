#include "header.h"

class TimeMap {
private:
    unordered_map<string, map<int, string>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(m.count(key) == 0) return "";

        auto& mm = m[key];
        auto iter = mm.lower_bound(timestamp);
        if(iter == mm.end())
        {
            return mm.rbegin()->second;
        }
        if(iter->first == timestamp) return iter->second;
        if(iter == mm.begin()) return "";
        --iter; 
        return iter->second;
    }
};

int main()
{
    //Solution s;
}
