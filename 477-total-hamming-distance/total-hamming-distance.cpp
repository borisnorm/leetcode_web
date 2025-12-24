class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++)
        {
            int one_cnt = 0;
            for (int num : nums)
              if (num & (1 << i))
                one_cnt++;

            int zero_cnt = n - one_cnt;
            // 形成 (0, 1) pair 所以是乘积 
            res += one_cnt * zero_cnt;
        }

        return res;
    }
};