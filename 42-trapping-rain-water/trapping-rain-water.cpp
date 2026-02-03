class Solution {
public:
    int trap(vector<int>& height) {
    
         int n = height.size();
         if (n <= 2)
           return 0;

         int l = 0;
         int r = n-1;

         int l_max = 0;
         int r_max = 0;

         int ans = 0;

         //l == r 时，该点已经无法形成左右围栏，不可能存水，因此循环条件用 l < r。
         while (l < r)
         {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            
            if (l_max <= r_max)
            {
               ans += l_max - height[l];  
               l++;
            }
            else
            {
               ans += r_max - height[r];
               r--;
            }
         }

         return ans;
    }
};