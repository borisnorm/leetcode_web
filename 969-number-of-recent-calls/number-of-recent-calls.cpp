class RecentCounter {
public:
    queue<int> req_queue;
    RecentCounter() {
       while(!req_queue.empty())
         req_queue.pop();
    }
    
    int ping(int t) {
       
        int left = req_queue.front();
        int right= t;

        while(!req_queue.empty() && (right-left) > 3000)
        {
          req_queue.pop();
          left = req_queue.front();
        }
        req_queue.push(t);

        return req_queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */