class SummaryRanges {
private:
    map<int, int> intervals; // start -> end mapping
    
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        // Find the first interval whose start is > value
        auto next = intervals.upper_bound(value);
        
        // Check previous interval (if exists)
        auto prev = next;
        if (next != intervals.begin()) {
            --prev;
        } else {
            prev = intervals.end();
        }
        
        // Check if value already covered by previous interval
        if (prev != intervals.end() && prev->first <= value && value <= prev->second) {
            return; // Already in an interval
        }
        
        // Determine merge scenarios
        bool mergePrev = (prev != intervals.end() && prev->second + 1 == value);
        bool mergeNext = (next != intervals.end() && value + 1 == next->first);
        
        if (mergePrev && mergeNext) {
            // Merge all three: prev interval + value + next interval
            prev->second = next->second;
            intervals.erase(next);
        } else if (mergePrev) {
            // Extend previous interval
            prev->second = value;
        } else if (mergeNext) {
            // Extend next interval backwards
            int nextEnd = next->second;
            intervals.erase(next);
            intervals[value] = nextEnd;
        } else {
            // Create new interval
            intervals[value] = value;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (const auto& [start, end] : intervals) {
            result.push_back({start, end});
        }
        return result;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */