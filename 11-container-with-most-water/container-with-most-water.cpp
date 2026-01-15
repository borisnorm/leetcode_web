class Solution {
public:
    int maxArea(vector<int>& height) {

         int n = height.size();
         int left = 0;
         int right = n-1;
         int maxArea = 0;

         while (left < right)
         {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = h * w;
            maxArea = max(maxArea, area);
            

           // for next higher height for shorter side;
           // higher height can get large area, even with less width.
           // 在短板一侧 向前移动找更大的挡板, 去计算可能的更大值, 挡板越大,蓄水越多
            if (height[left] < height[right])
              left++;
            else
              right--;
         }

         return maxArea;  
    }
};