class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        long long prefixSum = 0;
        unordered_map<int, int> remain2idx = {{0, -1}};
        
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
           prefixSum += nums[i];

           int remain = prefixSum % k;
           if (remain2idx.count(remain))
           {
              int preIdx = remain2idx[remain];
              if (i - preIdx >=2)
              {
                return true;
              }
           }
           else
             remain2idx[remain] = i;
        }

        return false;
    }
};