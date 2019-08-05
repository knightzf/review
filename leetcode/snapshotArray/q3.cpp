#include "header.h"

class SnapshotArray {
private:
    int sz;
    int snapid = 0;
    unordered_map<int, int> m;
    unordered_map<int, unordered_map<int, int>> snapshot;
public:
    SnapshotArray(int length) : sz(length) {

    }

    void set(int index, int val) {
        m[index] = val;
    }

    int snap() {
        snapshot[snapid] = m;
        return snapid++;
    }

    int get(int index, int snap_id) {
        if(snapshot[snap_id].count(index)) return snapshot[snap_id][index];
        return 0;
    }
};

int main()
{
}

