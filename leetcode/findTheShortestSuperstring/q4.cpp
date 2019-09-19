#include "header.h"

class Solution {
private:
    unordered_map<string, string> mm;
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        mm.clear();
        return impl(A, 0, n);
    }

    string impl(vector<string>& A, int startIdx, int n) {
        if(startIdx == n - 1) return A[startIdx];
        if(startIdx == n - 2) return combine(A[startIdx], A[startIdx + 1]);
        string sum;
        for(int i = startIdx; i < n; ++i)
            sum += A[i];
        
        string key = sum; 
        sort(key.begin(), key.end());
        if(mm.count(key)) return mm[key];

        for(int i = startIdx; i < n; ++i)
        {
            swap(A[startIdx], A[i]);
            const auto& res = impl(A, startIdx + 1, n);            
            const auto& t = combine(A[startIdx], res);
            if(t.size() < sum.size()) sum = t;
            swap(A[startIdx], A[i]);
        }

        mm[key] = sum;
        return sum;
    }

    string combine(const string& a, const string& b)
    {
        if(a.find(b) != -1) return a;
        if(b.find(a) != -1) return b;
        int n = a.size(), m = b.size();
        
        int c = 0, d = 0;
        int i = 0;
        while(i < m && i < n)
        {
            if(a.substr(n - i) == b.substr(0, i)) c = i;
            if(b.substr(m - i) == a.substr(0, i)) d = i;
            ++i;
        }       

        if(c > d) return a + b.substr(c);
        return b + a.substr(d);
    }
};

int main()
{
    Solution s;
    vector<string> a{"catg","ctaagt","gcta","ttca","atgcatc"};
    //s.shortestSuperstring(a);

    std::cout<<s.combine("gcta", "ctaagttcatgcatc")<<endl;
}
