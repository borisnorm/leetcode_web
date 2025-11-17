class RandomizedSet {
    unordered_map<int, int> valToIndex;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
      if (!valToIndex.count(val))
      {
         nums.push_back(val);
         valToIndex[val] = nums.size()-1;
         return true;
      }
      else
        return false;
    }
    
    bool remove(int val) {
        auto it = valToIndex.find(val);
        if (it == valToIndex.end())
          return false;
        int idx = it->second;
        int lastVal = nums.back();

        nums[idx] = lastVal;
        valToIndex[lastVal] = idx;

        nums.pop_back();

        valToIndex.erase(it);

        return true;
    }
    
    int getRandom() {
        int n = nums.size();
        int idx = rand() % n;
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */