class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
         int n = nums.size();
         int j = 1;
         for (int i = 0; i < n; i+=2)
         {
            if (nums[i] & 0x1)
            {
               // 奇数位 去找 非奇数
               while (nums[j]& 0x1)
                j += 2;
               
               swap(nums[i], nums[j]);
            }
         }

         return nums;
    }
};