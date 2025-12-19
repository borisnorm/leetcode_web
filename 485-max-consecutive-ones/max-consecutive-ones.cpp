class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int zero_cnt = 0;
        int max_zero_cnt  = INT_MIN;
        for (int i = 0; i < n; i++)
        {
           if (nums[i] == 1)
             zero_cnt++;
           else
             zero_cnt = 0;
           
           max_zero_cnt = max(max_zero_cnt, zero_cnt);
        }

        return max_zero_cnt;
    }
};