class MyCircularQueue
{
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int> q;
    int count, i, n;
    MyCircularQueue(int k) : count(0), n(k), i(0), q(vector<int>(k, 0)) {}

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        q[(i + count) % n] = value;
        count++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
            return false;
        i++;
        if (i >= n)
            i %= n;
        count--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (isEmpty())
            return -1;
        return q[i];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (isEmpty())
            return -1;
        return q[(i + count - 1) % n];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return count == 0 ? true : false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return count == n ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */