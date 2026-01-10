class SnapshotArray {
public:

    vector<vector<pair<int, int>>> history;
    int curSnapNum;
    SnapshotArray(int length) {
        history.resize(length);
        curSnapNum = 0;
        
        for (int i = 0; i < length; i++)
          // {snap_id, val}
          history[i].push_back({0, 0});
    }
    
    void set(int index, int val) {
        auto& vec = history[index];
        if (vec.back().first  == curSnapNum)
          vec.back().second = val;
        else
          vec.push_back({curSnapNum, val});
    }
    
    int snap() {
        return curSnapNum++;
    }
    
    int get(int index, int snap_id) {
        auto& vec = history[index];
        int l = 0;
        int r = vec.size();

        // find the last idx <= snap_id = first > snap_id - 1
        while (l < r)
        {
           int mid = l + (r-l)/2;
           if (vec[mid].first <= snap_id)
             l = mid + 1;
           else
             r = mid;
        }

        return vec[l-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */