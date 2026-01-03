class BoundedBlockingQueue {
public:
    int cnt;
    int cap;
    vector<int> cirBuf;
    mutex mtx;
    int front;
    int rear;
    
    condition_variable not_full;
    condition_variable not_empty;
    BoundedBlockingQueue(int capacity): cnt(0), cap(capacity), cirBuf(capacity), front(0), rear(0) {
        
    }
    
    void enqueue(int element) {
       unique_lock lck(mtx);
       not_full.wait(lck, [&]{ return cnt < cap;});
       
       cirBuf[rear] = element;
       rear = (rear + 1) % cap;
       cnt++;

       not_empty.notify_one();
    }
    
    int dequeue() {
        int val;
        unique_lock lck(mtx);
        not_empty.wait(lck, [&]{ return cnt > 0;});
        
        val = cirBuf[front];
        front = (front + 1) % cap;
        cnt--;

        not_full.notify_one();
        return val;
    }
    
    int size() {
        lock_guard lck(mtx);
        return cnt;
    }
};