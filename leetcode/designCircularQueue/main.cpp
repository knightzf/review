#include "header.h"

class MyCircularQueue {
    vector<int> v;
    int sz;
    int startIdx;
    int endIdx;
    bool empty;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        sz = k;
        v = vector<int>(sz, 0);
        empty = true;
        startIdx = -1;
        endIdx = -1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;

        int t = (endIdx + 1) % sz;
        v[t] = value;
        endIdx = t;

        if(empty)
        {
            startIdx = 0;
            empty = false;
        }

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        if(startIdx == endIdx)
        {
            startIdx = -1;
            endIdx = -1;
            empty = true;
        }
        else
            startIdx = (startIdx + 1) % sz;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(empty) return -1;
        return v[startIdx];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(empty) return -1;
        return v[endIdx];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return empty;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return sz == 0 || (endIdx + 1) % sz == startIdx;
    }
};

int main() {
    //Solution s;
}
