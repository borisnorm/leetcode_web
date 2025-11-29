class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> val2freq;
 
        int n = nums.size();
        for (int i = 0; i <  n; i++)
          val2freq[nums[i]]++;
        
        for (auto it: val2freq)
        {
          if (it.second > 1)
            res.push_back(it.first);
        }

        return res;
    }
};