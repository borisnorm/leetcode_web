class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        if (nums.empty())
          return 0;

        int n = nums.size();
        int maxVal = INT_MIN;
        for (int& num: nums)
          maxVal = max(maxVal, num);

        vector<int> points(maxVal + 1, 0);
        for(int num: nums)
          points[num] += num;
        
        int prev2 = 0;
        int prev1 = points[1];
        
        for (int i = 2; i <= maxVal; i++)
        {
           int prev = max(prev1, prev2 + points[i]);
           prev2 = prev1;
           prev1 = prev;
        }

        return prev1;
    }
};