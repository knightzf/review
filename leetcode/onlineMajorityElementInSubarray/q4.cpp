#include "header.h"

class MajorityChecker {
private:
    vector<int>& data;
    unordered_map<int, vector<int>> m;
public:
    MajorityChecker(vector<int>& arr) : data(arr) {
        for(int i = 0, n = arr.size(); i < n; ++i)
            m[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {
        for(int i = 0; i < 20; ++i) {
            int idx = left + rand() % (right - left + 1);
            int num = data[idx];
            auto iter = lower_bound(m[num].begin(), m[num].end(), left);
            auto jter = upper_bound(m[num].begin(), m[num].end(), right);
            if(distance(iter, jter) >= threshold) return num;
        }
        return -1;
    }
};

int main()
{
    //Solution s;
}
