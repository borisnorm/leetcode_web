#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    long long maxSumTrionic(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        long long ans = LLONG_MIN;

        while (i < n)
        {
            int l = i;
            i++;

            // 找左递增段的末尾 p（i停在第一个不再递增的位置）
            while (i < n && nums[i - 1] < nums[i])
            {
                i++;
            }

            // 左递增段至少需要2个元素，否则跳过
            if (i == l + 1)
            {
                continue;
            }

            // p 是峰（左递增段的最后一个元素）
            int p = i - 1;

            // 核心：从 nums[p-1]+nums[p] 开始（必须包含峰和峰左邻）
            long long s = (long long)nums[p - 1] + nums[p];

            // 找中间递减段，累加递减段的值
            while (i < n && nums[i - 1] > nums[i])
            {
                s += nums[i];
                i++;
            }

            // 递减段至少需要2个元素（p到q），且 q 之后必须还有元素
            // i==p+1 说明没有下降，i==n 说明右侧没有递增段
            if (i == p + 1 || i == n || nums[i - 1] == nums[i])
            {
                continue;
            }

            // q 是谷（递减段的最后一个元素）
            int q = i - 1;

            // 必须包含谷和谷右邻
            s += nums[i];
            i++;

            // 右侧递增段：贪心向右累加，只保留正收益的前缀最大值
            long long mx = 0, t = 0;
            while (i < n && nums[i - 1] < nums[i])
            {
                t += nums[i];
                i++;
                mx = max(mx, t);  // 取右侧递增段的最大前缀和
            }
            s += mx;

            // 左侧递增段：贪心向左累加，只保留正收益的后缀最大值
            mx = 0; t = 0;
            for (int j = p - 2; j >= l; j--)
            {
                t += nums[j];
                mx = max(mx, t);  // 取左侧递增段的最大后缀和
            }
            s += mx;

            ans = max(ans, s);

            // 从 q 重新开始（q 可能是下一段的起点）
            i = q;
        }

        return ans;
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