#include "header.h"

struct Encode
{
    Encode *obj;
    string str;
    int n;
    long len;
};

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        Encode* prev = nullptr;
        int startIdx = -1;
        int n = S.size();
        for(int i = 0; i < n; ++i)
        {
            if(islower(S[i]) && startIdx == -1)
            {
                startIdx = i;
            }
            if(isdigit(S[i]) || i == n - 1)
            {
                Encode* e = new Encode();
                e->obj = prev;
                if(isdigit(S[i]))
                {
                    e->str = startIdx!= -1 ? S.substr(startIdx, i - startIdx) : "";
                    e->n = S[i] - '0';
                }
                else
                {
                    e->str = startIdx!= -1 ? S.substr(startIdx) : string(1, S[i]);
                    e->n = 1;
                }

                e->len = ((e->obj ? e->obj->len : 0) + e->str.size()) * e->n;
                prev = e;
                startIdx = -1;
            }
        }

        return string(1, findIdx(prev, K));
    }

    char findIdx(Encode* e, int K)
    {
        //cout<<"a "<<e->len<<" "<<e->n<<endl;
        long single = e->len / e->n;
        if(single - e->str.size() > K)
        {
            return findIdx(e->obj, K);
        }

        int n = (K % single) ? (K % single - 1) : (single - 1);
        //cout<<"test "<<n<<" "<<single<<" "<<K<<endl;
        if(n < single - e->str.size())
        {
            return findIdx(e->obj, n + 1);
        }

        //cout<<n - single + e->str.size()<<" "<<e->str<<endl;
        return e->str[n - single + e->str.size()];
    }
};

int main()
{
    Solution s;
    //cout<<s.decodeAtIndex("leet2code3", 10)<<endl;
    //cout<<s.decodeAtIndex("ha22", 5)<<endl;
    //cout<<s.decodeAtIndex("a2345678999999999999999", 1)<<endl;
    cout<<s.decodeAtIndex("abc", 3)<<endl;
}

