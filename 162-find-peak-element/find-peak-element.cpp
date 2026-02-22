class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
          return INT_MIN;

        int n = nums.size();

        int l = 0;

        //当 r = n 的时候 
        //最坏情况: l = n-1, r = n
        //mid = (n-1) + (n - (n-1)) / 2 = n-1
        //mid + 1 = n   ← 越界！
        int r = n-1;
        
        // find pivot of the array 
        // so using l < r
        // 
        // 如果使用 while(l <= r)
        // when found peak l = r;  此时 mid 已经是最大值了
        // nums[mid]  > nums[mid+1]
        //  r = mid; 进入死循环.
        // 同时 当 while (l <= r)，l = r = n-1, nums[mid+1] 时会越界
        //
        //二分不需要找到所有峰值，只需要保证：每次缩小范围时，至少有一个峰值
        //往右走（l = mid+1）：右侧在上坡，边界是 -∞，必然有峰
        //往左走（r = mid）：mid 本身可能是峰，保留它
        while (l < r)
        {
            int mid = l + (r-l)/2;

            if (nums[mid] < nums[mid+1])
              l = mid + 1;
            else
              r = mid;
        }

        return l;
    }
};