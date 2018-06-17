#include "header.h"

class Solution {
private:
    unordered_map<string, int> visited;
public:
    int kSimilarity(string A, string B) {
        int n = A.size();
        if(n == 1) return 0;
        /*vector<unordered_set<int>> v(5);
        for(int i = 0; i < n; ++i)
        {
            v[A[i] - 'a'].insert(i);
        }*/
        visited.clear();
        return impl(A, B, n, 0);
    }

    int impl(string& A, string& B, int n, int i)
    {
        if(i == n) return 0;
        if(A[i] == B[i]) return impl(A, B, n, i + 1);

        if(visited.count(A)) return visited[A];
        int res = INT_MAX;
        for(int j = i + 1; j < n; ++j)
        {
            if(A[j] == B[i])
            {
                string t = A;
                swap(t[i], t[j]);
                res = min(res, impl(t, B, n, i + 1));
            }
        }
        visited[A] = res + 1;
        return res + 1;
    }
};

int main()
{
    Solution s;
    cout<<s.kSimilarity("aaaabbbbccccddddeeee", "bddceeceababeccddaab")<<endl;
}
