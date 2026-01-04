class SummaryRanges {
public:
    map<int, int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        
       // first > value
       auto next = mp.upper_bound(value);

       map<int, int>::iterator prev;
       if (next == mp.begin())
         prev = mp.end();
       else if (next == mp.end())
         prev = std::prev(next);
         //prev = next--;
       else
         prev = std::prev(next);
         //prev = next--;

    
      if (prev != mp.end() && prev->first <= value && value <= prev->second)
        return;
    
      bool mergeLeft = ((prev != mp.end()) && (prev->second + 1 == value)) ? true : false;
      bool mergeRight = ((next != mp.end()) && (value + 1 == next->first)) ? true : false;

      if (mergeLeft && mergeRight)
      {
          prev->second = next->second;
          mp.erase(next);
      }
      else if (mergeLeft)
      {
         prev->second = value;
      }
      else if (mergeRight)
      {
         int nextEnd = next->second;
         mp[value] = nextEnd;
         mp.erase(next);
      
      }
      else
      {
         mp[value] = value;
      }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto [start, end]: mp)
          res.push_back({start, end});


        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */