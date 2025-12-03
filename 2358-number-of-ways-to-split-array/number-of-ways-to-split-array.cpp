class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       
       long long prefixSum = 0;
       long long postfixSum = 0;
    
       int n = nums.size();
       int cnt = 0;

       long long total = 0;
       for (auto x: nums)
         total += x;

       for (int i = 0; i < n - 1; i++)
       {
          prefixSum += nums[i];
          postfixSum = total - prefixSum;

          if (prefixSum >= postfixSum)
            cnt++;
       }

       return cnt;
    }
};