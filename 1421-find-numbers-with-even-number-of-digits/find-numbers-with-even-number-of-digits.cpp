class Solution {
public:
    int findNumbers(vector<int>& nums) {
       
       int cnt = 0;
       for (int num : nums)
       {
          string num_str = to_string(abs(num));

          if (!(num_str.size() & 0x1))
            cnt++;
       }
       return cnt;
    }
};
/*
class Solution {
public:
    int findNumbers(vector<int>& nums) {
      // 
      // 10 <= x < 100 // even 2
      // 1000 <= x < 10000  // 4
      // 100000 <= x < 1000000 
      int n = nums.size();
      int cnt = 0;
      for (int i = 0; i < n; i++)
      {
        int x = nums[i];
        int digit_cnt = 0;
        while (x)
        {
           digit_cnt++;
           x = x/10;
        }

        if (digit_cnt % 2 == 0)
          cnt++;
      }
        return cnt;
    }
};

*/