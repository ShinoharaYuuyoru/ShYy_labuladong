/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
   private:
    deque<NestedInteger> list;

   public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        list = deque<NestedInteger>(nestedList.begin(), nestedList.end());
    }

    int next() {
        int val = list.front().getInteger();
        list.pop_front();
        return val;
    }

    bool hasNext() {
        while (1) {
            if (list.empty()) {
                return false;
            } else {
                if (list.front().isInteger()) {
                    return true;
                } else {
                    vector<NestedInteger> temp = list.front().getList();
                    list.pop_front();
                    for (int i = temp.size() - 1; i >= 0; i--) {
                        list.push_front(temp[i]);
                    }
                }
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */