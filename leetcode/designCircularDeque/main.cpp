#include "header.h"

class MyCircularDeque {
private:
    int sz;
    vector<int> data;
    int cnt = 0;
    int endIdx = -1;

    int frontIdx() {
        return (endIdx + sz - cnt + 1) % sz;
    }

    int nextFrontIdx() {
        return (endIdx + sz - cnt) % sz;
    }

    int nextRearIdx() {
        return (endIdx + 1) % sz;
    }

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : sz(k) {
        data = vector<int>(k, 0);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        data[nextFrontIdx()] = value;
        ++cnt;
        if(endIdx == -1) endIdx = sz - 1;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        data[nextRearIdx()] = value;
        endIdx = nextRearIdx();
        ++cnt;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        --cnt;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        --cnt;
        endIdx = (endIdx + sz - 1) % sz;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return data[frontIdx()];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return data[endIdx];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == sz;
    }
};


int main()
{
    //Solution s;
}