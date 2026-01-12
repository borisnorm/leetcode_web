class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
          return 0;

        int maxVal = INT_MIN;
        int minVal = INT_MAX;

        for (int i = 0; i < n; i++)
        {
           maxVal = max(maxVal, nums[i]);
           minVal = min(minVal, nums[i]);
        }
        
        if (maxVal == minVal)
          return 0;

        int bucketSize = ((maxVal - minVal + n - 2)/(n-1));
        int bucketCnt  = (maxVal - minVal)/bucketSize + 1;

        vector<int> bucketMin(bucketCnt, INT_MAX);
        vector<int> bucketMax(bucketCnt, INT_MIN);
        vector<int> used(bucketCnt, 0);

        for (int num : nums)
        {
           int idx = (num - minVal) / bucketSize;
           bucketMin[idx] = min(bucketMin[idx], num);
           bucketMax[idx] = max(bucketMax[idx], num);
           used[idx] = 1;
        }

        int preMax = minVal;
        int ans  = 0;
        for (int i = 0; i < bucketCnt; i++)
        {
            if (!used[i])
              continue;

            int diff = bucketMin[i] - preMax;
            ans = max(ans, diff);
          
            preMax = bucketMax[i];
        }

        return ans;
    }
};