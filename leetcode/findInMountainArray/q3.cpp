#include "header.h"

class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, h = n - 1;
        while(l < h) {
            int m = (l + h) / 2;
            int a = mountainArr.get(m), b = mountainArr.get(m + 1);
            if(a < b) l = m + 1;
            else h = m - 1;
        }
        int idx = l;
        cout<<idx<<endl;
        l = 0, h = idx;
        while(l <= h) {
            int m = (l + h) / 2;
            int t = mountainArr.get(m);
            if(t == target) return m;
            if(t > target) h = m - 1;
            else l = m + 1;
        }

        l = idx; h = n - 1;
        while(l <= h) {
            int m = (l + h) / 2;
            int t = mountainArr.get(m);
            if(t == target) return m;
            if(t > target) l = m + 1;
            else h = m - 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
}

