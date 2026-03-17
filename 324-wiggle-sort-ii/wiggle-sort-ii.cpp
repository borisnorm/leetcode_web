class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //对应到**物理空间**（经过 idx 映射）：
        //逻辑前段 i=0,1,2  → 物理奇数位 1,3,5  ← 放"大于m"的元素
        //逻辑后段 i=3,4,5  → 物理偶数位 0,2,4  ← 放"小于m"的元素
        // 逻辑中段          → 剩余位置          ← 放"等于m"的元素
        int n = nums.size();
        // 1 2 3 4 5
        // 0 1 2 3 4      (5-1)/2 = 2
        // 1 2 3 4 5 6    (6-1)/2 = 2
         // 0 1 2 3 4 5
        int mid = (n-1)/2; 
        nth_element(nums.begin(), nums.begin()+ mid, nums.end());
        int median = nums[mid];

        auto idx = [&](int i) {return (2 * i + 1) % (n | 1); };
      
        // low 下一个 大于m 的位置
        // high 下一个 小于m 的位置 
        int low = 0;
        int high = n - 1;
        int cur = 0;
        
        while (cur <= high)
        {
           if (nums[idx(cur)] > median)
           {
             swap(nums[idx(cur)], nums[idx(low)]);
             low++;
             cur++;
           }
           else if (nums[idx(cur)] == median)
           {
              cur++;
           }
           else
           {
              swap(nums[idx(cur)], nums[idx(high)]);
              high--;
           }
        }
    }
};