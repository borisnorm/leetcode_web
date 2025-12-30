class MovingAverage {
public:
    
    double sum = 0.0;
    int maxqsz = 0;
    queue<int> q;
    MovingAverage(int size) {
        maxqsz = size;
    }
    
    double next(int val) {
        if (q.size() == maxqsz)
        {
           int val = q.front();
           sum -= val;
           q.pop();
        }

        q.push(val);
        sum += val;

        int qcnt = q.size();
        return sum/qcnt;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */