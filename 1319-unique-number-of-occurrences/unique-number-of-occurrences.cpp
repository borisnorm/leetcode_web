class Solution {
public:

    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> val2freq;
        for (int val : arr)
          val2freq[val]++;
        
        unordered_set<int> freq_set;
        for (auto& it : val2freq)
        {
          if (!freq_set.count(it.second))
            freq_set.insert(it.second);
          else
            return false;
        }
        return true;
    }
/*
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> val2freq;
        for (int val : arr)
          val2freq[val]++;
        
        unordered_map<int, int> freq2occur;
        for (auto& it : val2freq)
        {
          freq2occur[it.second]++;
          if (freq2occur[it.second] > 1)
            return false;
        }
        
        return true;
    }
*/
};