class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3)
          return 0;
        sort(nums.begin(), nums.end());

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int l = i + 1;
            int r = n - 1;
            int remain = target - nums[i];

            while (l < r)
            {
                int sum = nums[l] + nums[r];
                
                if (sum < remain)
                {
                   cnt += r-l;
                   l++;
                }
                else if (sum >= remain)
                {
                    r--;
                }
            }

        }

        return cnt;
    }
};