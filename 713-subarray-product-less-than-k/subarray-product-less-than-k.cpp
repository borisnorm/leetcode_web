class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        

         int n = nums.size();
         int l = 0;
         int r = 0;
         int product = 1;

         int res = 0;
 
         while (r < n)
         {
            product *= nums[r];
            r++;

            while (l < r && product >= k)
            {
               product /= nums[l];
               l++;
            }
            
            // r, l 代表 以 r 为结尾的 子数组的一个集合, 左端点可以以 l, 或是 l+1, 或是 l+2开始,
            //{ l, l+1, ..., r }
            // {   l+1 , ....r }
            // {       l+2.... r}}
            // 所以 r-l 就是 结合的大小了
            // 这里 r 先 ++了,  结果就是  r-1 - l +1 =  r-l
            res+=(r-l);

         }

         return res;
    }
};