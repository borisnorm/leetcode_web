class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long sum = 0;
        int maxOps = 0;
        int l = 0;
        int r = 0;
        while (r < n)
        {
           sum += nums[r];
           r++;
          
           // 假设window内所有的数都是 nums[r],
           while (1LL * nums[r-1] * (r-l) - sum > k)
           {
              sum -= nums[l];
              l++;
           }

           maxOps = max(maxOps, r-l);
        }

        return maxOps;
    }
};