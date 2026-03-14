class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // <= k  

        if (k < 0)
          return 0;

        int n = nums.size();
        int l = 0;
        int r = 0;
        long long cnt = 0;
        long long sum = 0;

        while (r < n)
        {
            sum += nums[r];
            r++;
            
            while (sum * (r-l) >= k)
            {
               sum -= nums[l];
               l++;
            }

            cnt += r-l;
        }
        return cnt;
    }
};