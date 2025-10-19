class Solution {
public:
    int trap(vector<int>& height) {
         if (height.empty())
           return 0;
    
         int n = height.size();
         if (n <= 2)
           return 0;

         int left = 0;
         int right = n-1;

         int l_max = 0;
         int r_max = 0;

         int ans = 0;

         while (left < right)
         {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if (l_max <= r_max)
            {
               ans += l_max - height[left];  
               left++;
            }
            else
            {
               ans += r_max - height[right];
               right--;
            }
         }

         return ans;
    }
};