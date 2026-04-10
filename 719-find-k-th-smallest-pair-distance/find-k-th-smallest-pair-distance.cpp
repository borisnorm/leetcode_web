class Solution {
public:

    int countPairs(vector<int>& nums, int mid)
    {
       int cnt = 0;
       int i = 0;
       int n = nums.size();

       for (int j = 1; j < n; j++)
       {
          // 缩小 左端, 保证 nums[j] - nums[i] <= mid
          while (nums[j] - nums[i] > mid)
            i++;
          // 以 j 为 右端,
          // 合法左端为 [i, j-1]共 j-i 个 pair
          cnt += j - i;
       }

       return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums.back() - nums.front();

        while (lo < hi)
        {
           int mid = lo + (hi-lo)/2;
           // 二分答案：找最小的 mid 使得 countPairs >= k
           if (countPairs(nums, mid) >= k)
             hi = mid;
           else
             lo = mid + 1;
        }
        return lo;
    }
};