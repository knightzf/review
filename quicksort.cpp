#include "header.h"

class Solution {
public:
    int partition(vector<int>& v, int l, int h) {
        int m = (l + h) / 2, pivot = v[m];
        while(true) {
            while(v[l] < pivot) ++l;
            while(v[h] > pivot) --h;
            if(l >= h) return h;
            swap(v[l++], v[h--]);
        }
        return -1;
    }

    void quicksort(vector<int>& v, int l, int h) {
        if(l >= h) return;
        int idx = partition(v, l, h);
        quicksort(v, l, idx);
        quicksort(v, idx + 1, h);
    }
};

int main()
{
    Solution s;
    vector<int> a{0};
    s.quicksort(a, 0, a.size() - 1);
    for(int i : a) cout<<i<<" "; cout<<endl;
}