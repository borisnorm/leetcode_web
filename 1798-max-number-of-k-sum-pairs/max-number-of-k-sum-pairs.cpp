class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> nums2idx;
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        { 
           int target = k - nums[i];
           bool ignored = false;
           if (nums2idx.count(target))
           {
              int pre_idx = nums2idx[target];
              int cur_idx = i;

              nums[pre_idx] = INT_MAX;
              nums[cur_idx] = INT_MAX;
              
              nums2idx[target]--;
              if (nums2idx[target] <= 0)
                nums2idx.erase(target);

              ignored = true;     

              cnt++;        
           }
           else
             nums2idx[nums[i]]++;
        }

        int write = 0;
        for (int i = 0; i < n; i++)
        {
          if (nums[i] != INT_MAX)
            nums[write++] = nums[i];
        }

        nums.resize(write);

        return cnt;
    }
};