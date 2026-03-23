class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;

        for (int prime_num: nums)
        {
           if (prime_num == 2)
           {
              res.push_back(-1);
              continue;
           }

            // ans | ans + 1 = prime_num (奇数)
            // ans + 1 将 ans 的最低位0 设为了 1
            // 反向 就是找最低位的 1, 然后 清掉它          
           int ans = INT_MAX;
           for (int i = 0; i < 30; i++)
           {
              // 
              if ((prime_num >> i) & 0x1 == 0)
                continue;
              
              int cand =  prime_num ^ (1 << i);

              if ((cand | cand+1) == prime_num)
                ans = min(ans, cand);
           }
          
           if (ans == INT_MAX)
             ans = -1;
           res.push_back(ans);
        }

        return res;
    }
};