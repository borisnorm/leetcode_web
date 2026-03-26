class Solution {
public:
    vector<int> memo;
    int racecar(int target) {       
       memo.assign(target+1, -1);
       return dfs(target);
    }

    int dfs(int target)
    {
       if (target == 0)
         return 0;
       
       if (memo[target] != -1)
         return memo[target];
       
       int k = 1;
       // 1 + 2 + 4 + 8 +  = 2^n -1
       // 连续走k步后的 pos
       while((1 << k) - 1 < target)
         k++;
      
       int full = (1 << k) - 1;
       if (full == target)
       {
          memo[target] = k;
          return memo[target];
       }

       // 策略1
       // 冲过头后 向回走了一次 R, +1, 再解决剩余距离
       int ans = k + 1 + dfs(full-target);

       // 策略2 前进 k-1 + R + 后退 m 步 + R, 
       // 2次 R 变正向
       int pre = (1 << (k-1)) - 1;
       for (int m = 0; m < k - 1; m++)
       {
          int back = (1 << m) - 1;
          int remain = target - (pre - back);
          int steps = (k-1) + 1 + m + 1;
          ans = min(ans, steps + dfs(remain));
       }

       memo[target] = ans;
       return memo[target];
    }
};