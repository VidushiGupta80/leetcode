//Design Circular Queue -> 05/26/2020 20:51
class MyCircularQueue {
public:
    vector<int> myqueue;
    long long len;
    long long i, j, count;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        myqueue = vector<int>(k);
        len = k;
        i = -1;
        j = 0;
        count = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull())
        {
           if(isEmpty())
           {
               i = j;
               myqueue[j] = value;
               j = (j + 1) % len;
               count++;
           }
           else if(!isEmpty())
           {
               myqueue[j] = value;
                j = (j + 1) % len;
               count++;
           }
            return true;  
        }
        else
            return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            count--;
            i = (i + 1) % len;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(!isEmpty())
            return myqueue[i];
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(!isEmpty())
        {
            if(j == 0)
                return myqueue[len - 1];
            else
                return myqueue[j - 1];
        }
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(count == 0)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(j > i && (j - i) == len)
            return true;
        else if(i == j && count != 0)
            return true;
        else
            return false;
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