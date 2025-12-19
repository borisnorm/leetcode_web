class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num: nums)
          sum += num;
        
        if (sum % k != 0)
          return false;

        int target = sum / k;
    
        for (int num: nums)
          if (num > target)
             return false;

        // 降序 descending 排列
        sort(nums.begin(), nums.end(), greater<int>());

        vector<bool> visited(nums.size(), false);
        return backtrack(nums, visited, 0, k, 0, target);
    }

    bool backtrack(vector<int>& nums, vector<bool>& visited, int start, int k,
                   int currentSum, int target)
    {
        if (k == 1)
          return true;
        
        if (currentSum == target)
          return backtrack(nums, visited, 0, k-1, 0, target);

        for (int i = start; i < nums.size(); i++)
        {
            if (visited[i])
              continue;
            
            if (currentSum + nums[i] > target)
              continue;
            
            visited[i] = true;
            if (backtrack(nums, visited, start + 1, k, currentSum + nums[i], target))
              return true;

            visited[i] = false;

            if (currentSum == 0)
              break;
        }

        return false;
    }
};