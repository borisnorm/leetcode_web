class Solution
{
public:
    long long maxSumTrionic(vector<int>& nums)
    {
        int n = static_cast<int>(nums.size());                                   // 数组长度
        long long neg = numeric_limits<long long>::lowest() / 4;                 // 负无穷，防止后续加法溢出

        vector<long long> up(n, neg);                                            // up[i]：以 i 结尾的严格递增子数组最大和
        vector<long long> down(n, neg);                                          // down[i]：以 i 结尾的“递增+递减”子数组最大和
        vector<long long> up2(n, neg);                                           // up2[i]：以 i 结尾的“递增+递减+递增”子数组最大和

        long long ans = neg;                                                     // 记录最终答案

        for (int i = 1; i < n; i++)                                              // 从第 1 个位置开始，因为要和 i-1 比较
        {
            if (nums[i - 1] < nums[i])                                           // 当前是上升关系
            {
                long long start_up = 1LL * nums[i - 1] + nums[i];                // 新开一个长度为 2 的递增段
                long long extend_up = (up[i - 1] == neg ? neg : up[i - 1] + nums[i]); // 延长之前的递增段
                up[i] = max(start_up, extend_up);                                // 更新第一阶段

                long long start_up2 = (down[i - 1] == neg ? neg : down[i - 1] + nums[i]); // 从第二阶段切到第三阶段
                long long extend_up2 = (up2[i - 1] == neg ? neg : up2[i - 1] + nums[i]);  // 延长第三阶段
                up2[i] = max(start_up2, extend_up2);                             // 更新第三阶段
            }

            if (nums[i - 1] > nums[i])                                           // 当前是下降关系
            {
                long long start_down = (up[i - 1] == neg ? neg : up[i - 1] + nums[i]);     // 从第一阶段切到第二阶段
                long long extend_down = (down[i - 1] == neg ? neg : down[i - 1] + nums[i]); // 延长第二阶段
                down[i] = max(start_down, extend_down);                          // 更新第二阶段
            }

            ans = max(ans, up2[i]);                                              // 只有第三阶段才是完整 trionic，尝试更新答案
        }

        return ans;                                                              // 返回最大 trionic subarray sum
    }
};

/*
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for (int i = 0; i < n; i++)
          pre[i+1] = pre[i] + nums[i];
        
        //L 存递增起点
        vector<int> L(n);
        L[0] = 0;
        for (int i = 1; i < n; i++)
          L[i] = (nums[i-1] < nums[i]) ? L[i-1] : i;
        
        //R 存储递增终点
        vector<int> R(n);
        R[n-1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
          R[i] = (nums[i] < nums[i+1]) ? R[i+1] : i;
      
       long long maxSum = LLONG_MIN;
       int i = 0;
       while (i < n)
       {
          int p = i;
          while (p + 1 < n && nums[p] < nums[p+1])
            p++;
          
          if (p == n-1)
            break;
          
          int q = p;
          while (q + 1 < n && nums[q] > nums[q+1])
            q++;
          
          if (L[p] < p && R[q] > q)
          {
             long long sum = pre[R[q] + 1] - pre[L[p]];
             maxSum = max(maxSum, sum);
          }
          
          // 修复：从 q+1 开始，避免重复处理同一个 q
          i = (q > i) ? q : i + 1;  // q没动时强制前进
       }

       return maxSum;
    }
};

*/