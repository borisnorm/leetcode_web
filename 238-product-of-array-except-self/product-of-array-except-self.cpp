class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        if (nums.empty())
          return {};

        int n = nums.size();

        vector<int> res(n, 1);

        for (int i = 1; i < n; i++)
        {
           // res[i] 是 i 左边所有数的乘积
           // ans[i] = nums[0] * nums[1] * ... * nums[i-1]

          // 那 res[i-1] 是 i - 1 这个位置 左边 的所有数的乘积, 
          // 对于 i 来说就是 从 0 到 i-2的所有乘积
           res[i] = res[i-1] * nums[i-1];
        }

        int tmp = 1;
        for (int i = n - 1; i >= 0; i--)
        {
          // 先更新 倒数的 i, 因为不能 乘 它自己
          res[i] = res[i] * tmp;
          // 跟新 temp for 下一个数
          tmp = nums[i] * tmp;
        }

        return res;
    }
};