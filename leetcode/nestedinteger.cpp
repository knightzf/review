/**
 *  // This is the interface that allows for creating nested lists.
 *  // You should not implement it, or speculate about its implementation
 *  class NestedInteger {
 *  *   public:
 *      *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *       *     bool isInteger() const;
 *        *
 *         *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *          *     // The result is undefined if this NestedInteger holds a nested list
 *           *     int getInteger() const;
 *            *
 *             *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *              *     // The result is undefined if this NestedInteger holds a single integer
 *               *     const vector<NestedInteger> &getList() const;
 *                * };
 *                 */
class NestedIterator {
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            _index = 0;
            readVector(nestedList, _data);
        }

        void readVector(const vector<NestedInteger> &nestedList, vector<int>& data)
        {
            for(size_t i = 0, sz = nestedList.size(); i < sz; ++i)
            {
                if(nestedList[i].isInteger())
                {
                    _data.push_back(nestedList[i].getInteger());
                }
                else
                {
                    readVector(nestedList[i].getList(), _data);
                }
            }
        }

        int next() {
            return _data[_index++];
        }

        bool hasNext() {
            return _data.size() > _index;
        }

    private:
        size_t _index;
        vector<int> _data;
};

/**
 *   Your NestedIterator object will be instantiated and called as such:
 *   NestedIterator i(nestedList);
 *   while (i.hasNext()) cout << i.next();
 */
