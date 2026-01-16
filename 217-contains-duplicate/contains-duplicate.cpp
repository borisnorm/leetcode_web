class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int num: nums)
        {
           if (num_set.count(num))
             return true;
            
           num_set.insert(num);
        }
        return false;
    }

/*
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> num2freq;

        for (int num: nums)
        {
          num2freq[num]++;
          if (num2freq[num] >= 2)
            return true;
        }
        
        return false;
    }
*/
};