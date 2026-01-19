class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        // mostDist(k) (<= k) = f(1) + f(2) + f(3) + f(k)  
        return mostDist(nums, k) - mostDist(nums, k-1);
    }

    int mostDist(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (k > n)
          return 0;
        
        int l = 0;
        int r = 0;
        int distinct = 0;

        unordered_map<int, int> num2freq;
  
        int ans = 0;
        while (r < n)
        {
            if (num2freq[nums[r]] == 0)
              distinct++;
            num2freq[nums[r]]++;
            r++;
            
            while(distinct > k)
            {
               num2freq[nums[l]]--;
               if (num2freq[nums[l]] == 0)
                 distinct--;
               l++;
            }

            
            ans += (r - l);
        }

        return ans;

    }
};