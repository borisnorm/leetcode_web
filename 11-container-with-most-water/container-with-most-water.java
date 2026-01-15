class Solution {
    public int maxArea(int[] height) {
        if (height == null || height.length == 0)
          return 0;

        int n = height.length;
        int l = 0;
        int r = n - 1;
        int maxArea = 0;

        while (l < r)
        {
           int w = r - l;
           int h = Math.min(height[l], height[r]);
           int area = h * w;

           maxArea = Math.max(maxArea, area);

           // for next higher height for shorter side;
           // higher height can get large area, even with less width.
           // 在短板一侧 向前移动找更大的挡板, 去计算可能的更大值, 挡板越大,蓄水越多
           if (height[l] < height[r])
             l++;
           else
             r--;
        }

        return maxArea;
    }
}