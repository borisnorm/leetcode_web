class Solution {
public:
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
};