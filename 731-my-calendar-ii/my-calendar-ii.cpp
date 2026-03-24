class MyCalendarTwo {
public:
    vector<pair<int, int>> single;
    vector<pair<int, int>> overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        
      for(auto [lastOverlapStart, lastOverlapEnd]: overlap)
      {
          if (startTime < lastOverlapEnd && lastOverlapStart < endTime)
            return false;
      }


      for (auto [lastStartTime, lastEndTime]: single)
      { 
         //update 的反向 check
         int lo = max(lastStartTime, startTime);
         int hi = min(lastEndTime, endTime);
         if (lo < hi)
           overlap.push_back({lo, hi});
      }

      single.push_back({startTime, endTime});
      return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */