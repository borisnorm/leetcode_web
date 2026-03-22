class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // number of 1 
        int k = 0;
        for (int num: nums)
          k += num; 
        
        if (k == 0 || k == n)
          return 0;
        
        //窗口大小 [0, k-1]
        int one_cnt = 0;


        for(int i = 0; i < k; i++)
          if (nums[i] == 1)
            one_cnt++;
        int maxOneCnt = one_cnt;

       for (int r = k; r < n + k; r++)
       {
          one_cnt += nums[r % n];
          one_cnt -= nums[(r-k)%n];
          maxOneCnt = max(maxOneCnt, one_cnt);
       }

       return  k - maxOneCnt;
    }
};