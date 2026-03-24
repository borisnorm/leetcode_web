class MyCalendar {
public:

    // [start, end]
    map<int, int> calander;

    MyCalendar() {

    }
    
    bool book(int startTime, int endTime) {
        
        // first >= startTime point
        auto it = calander.lower_bound(startTime);

        // check 右邻居  
        if (it != calander.end() && it->first < endTime)
          return false;
        
        // check 左邻居
        if (it != calander.begin())
        {
           it--;
           if (it->second > startTime)
             return false;
        }

        calander[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */