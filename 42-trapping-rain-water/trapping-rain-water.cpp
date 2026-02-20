class Solution {
public:
    int trap(vector<int>& height) {
    
         int n = height.size();
         //只要2个的左右2段 无法储水, 至少要 3个, 水会从一边流出去
         if (n <= 2)
           return 0;

         int l = 0;
         int r = n-1;

         int l_max = 0;
         int r_max = 0;

         int res = 0;
        
         // 1. 两端开始遍历
         //l == r 时，该点已经无法形成左右围栏，不可能存水，因此循环条件用 l < r。
         while (l < r)
         {
            //2. 在 l, r 更新后, 确定 左右 板的的 最大值
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            // 比较的是 l_max 与  r_max 不是 height[l] 与 height[r]
            // 3.找短板, 根据短板计算当前 格子的储水量, 并累加
            if (l_max <= r_max)
            {
               res += l_max - height[l];  
               l++;
            }
            else
            {
               res += r_max - height[r];
               r--;
            }
         }

         return  res;
    }
};