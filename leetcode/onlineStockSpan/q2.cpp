#include "header.h"

class StockSpanner {
private:
    vector<int> v;
    vector<int> res;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        if(v.size() == 1)
        {
            res.push_back(1);
            return 1;            
        }

        int t = 1;
        int offset = 1;
        int idx = v.size() - 1;
        while(idx - offset >= 0 && v[idx - offset] <= price)
        {
            idx -= offset;
            offset = res[idx];
            t += offset;
        }

        res.push_back(t);
        return res.back();
    }
};

int main()
{
    //Solution s;
    StockSpanner s;
    cout<<s.next(100)<<endl;
    cout<<s.next(80)<<endl;
    cout<<s.next(60)<<endl;
    cout<<s.next(70)<<endl;
    cout<<s.next(60)<<endl;
    cout<<s.next(75)<<endl;
    cout<<s.next(85)<<endl;
}
