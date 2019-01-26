#include "header.h"

class UnionFind
{
public:
    UnionFind(int N)
    {
        for(int i = 0; i < N; i++) m[i] = i;
    }

    int root(int i)
    {
        while (i != m[i])
        {
            m[i] = m[m[i]];
            i = m[i];
        }
        return i;
    }

    bool find(int p, int q)
    {
        return root(p) == root(q);
    }

    void unite(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        m[i] = j;
    }

private:
    unordered_map<int, int> m; 
};

int main()
{
}