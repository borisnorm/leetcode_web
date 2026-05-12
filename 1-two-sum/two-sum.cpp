class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                     
        unordered_map<int, int> val2idx;
        
        int n = nums.size();
        for (int i = 0 ; i < n; i++)
        {
           int num = nums[i];
           int remain = target - num;
           if (val2idx.count(remain))
             return {val2idx[remain], i};
         
           val2idx[num] = i;
        }

        return {};
    }
};