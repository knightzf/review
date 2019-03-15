#include "header.h"

template<class T>
class LRU
{
public:
    LRU(int sz)
    {
        m_sz = sz;
    }

    void add(const string& key, const T& val)
    {
        if(m_map.count(key)) return;

        if(m_list.size() == m_sz)
        {
            const auto& t = m_list.back().first;
            m_map.erase(t);
            m_list.pop_back();
        }

        m_list.push_front(make_pair(key, val));
        m_map.emplace(key, m_list.begin());
    }

    T get(const string& key)
    {
        if(m_map.count(key) == 0) return T();

        auto p = m_map[key];
        m_list.push_front(*p);
        m_map[key] = m_list.begin();
        m_list.erase(p);
        return m_list.front().second;
    }

    void dump()
    {
        for(const auto& p : m_list)
            cout<<p.first<<" "<<p.second<<" | ";
        cout<<endl;
        cout<<"-------"<<endl;
    }

private:
    int m_sz;
    using List = list<pair<string, T>>;
    List m_list;
    unordered_map<string, typename List::iterator> m_map;
};

int main()
{
    //Solution s;
    LRU<int> cache(3);
    cache.add("a", 1);
    cache.add("b", 2);
    cache.add("c", 3);

    cout<<cache.get("b")<<endl;
    cout<<cache.get("a")<<endl;
    cache.add("d", 4);
    cout<<cache.get("c")<<endl;
    cache.dump();
}