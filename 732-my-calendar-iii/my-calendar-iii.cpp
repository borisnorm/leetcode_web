class MyCalendarThree {
public:
    // key: event(startTime, endTime) 强调 的是 event 事件的起始与结束
    // val: 变化量
    map<int, int> diff;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        diff[startTime]++;
        diff[endTime]--;
      
        int nOverlap = 0;
        int maxK = 0;

        for(auto [event_time, delta]: diff)
        {
            nOverlap += delta;
            maxK = max(maxK, nOverlap);
        }

        return maxK;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */