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
class NestedIterator
{
  public:
    vector<NestedInteger> stack;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int size = nestedList.size();
        for (int i = size - 1; i >= 0; i--)
        {
            stack.push_back(nestedList[i]);
        }
    }

    int next()
    {
        int ans = stack.back().getInteger();
        stack.pop_back();
        return ans;
    }

    bool hasNext()
    {
        while (!stack.empty())
        {
            if (stack.back().isInteger())
            {
                return true;
            }
            NestedInteger cur = stack.back();
            vector<NestedInteger> &tmp = cur.getList();
            stack.pop_back();
            int size = tmp.size();
            for (int i = size - 1; i >= 0; i--)
            {
                stack.push_back(tmp[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */