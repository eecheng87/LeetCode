class MyCircularDeque
{
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int> dq;
    int i, j, n, count;
    MyCircularDeque(int k)
    {
        vector<int> tmp(k, 0);
        dq = tmp;
        i = j = 0;
        n = k;
        count = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        i--;
        if (i < 0)
            i = n - 1;

        dq[i] = value;
        count++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;

        dq[(i + count) % n] = value;
        count++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        i++;
        i %= n;
        count--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        count--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;
        return dq[i];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;
        return dq[(i + count - 1) % n];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return count == 0 ? true : false;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return count == n ? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */