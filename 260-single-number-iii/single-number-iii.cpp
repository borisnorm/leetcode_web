class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long xor_res = 0;
        for (int num: nums)
          xor_res ^= num;

        // 找到 a 和 b 不同的某一位
        long long diff_bit = xor_res & (-xor_res);

        int a = 0;
        int b = 0;
        for (int num: nums)
        {
           if (num & diff_bit)
           {
              a ^= num;
           }
           else
           {
              b ^= num;
           }
        }

        return {a, b};
    }
};