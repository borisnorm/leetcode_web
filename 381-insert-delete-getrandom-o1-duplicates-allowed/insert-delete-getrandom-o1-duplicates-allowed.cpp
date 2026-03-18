class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        
        bool first = idx[val].empty() ? true: false; 
        nums.push_back(val);
        int val_idx = nums.size()-1;
        idx[val].insert(val_idx);
        return first;
    }
    
    bool remove(int val) {
        
        if (idx[val].empty())
          return false;
        
        int rmIdx   = *idx[val].begin();
        int lastIdx = nums.size()-1;
        int lastVal = nums.back();

        //  rmIdx <- lastIdx
        //  rmIdx_val <- lastVal

        nums[rmIdx] = lastVal;

        idx[val].erase(rmIdx);
        
        idx[lastVal].erase(lastIdx);
        if (rmIdx != lastIdx)
          idx[lastVal].insert(rmIdx);
        


        nums.pop_back();

        return true;

    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */