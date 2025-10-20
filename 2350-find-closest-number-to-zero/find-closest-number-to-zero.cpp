class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        if (nums.empty()) 
          return 0;  // 如果数组为空，返回 0

        int ans = INT_MAX;
        for(int num : nums)
        {
           if (abs(num) < abs(ans) || (abs(ans) == abs(num) && num > ans))
             ans = num;
        }

        return ans;
   
    }
};