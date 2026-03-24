class Solution {
public:

    vector<int> ans;
    void mergeSort(vector<pair<int, int>>& idx_arr, int l, int r)
    {
       // 0 个或 1 个元素不需要排序
       if (r - l <= 1)
         return;

       int mid = l + (r-l)/2;
       
       // call mergeSort 之前
       // [l, mid) 无序, [mid, r) 无序
       mergeSort(idx_arr, l, mid);
       mergeSort(idx_arr, mid, r);
       // call mergeSort 之后
       // [l, mid) 有序, [mid, r) 有序

       vector<pair<int, int>> tmp;
       int i = l;
       int j = mid;

       int right_picked = 0;

       while (i < mid & j < r)
       {
          if (idx_arr[j].first < idx_arr[i].first)
          {
             tmp.push_back(idx_arr[j++]);
             // 继续 count 比现在 i 要小的数的个数
             right_picked++;
          }
          else
          {
             ans[idx_arr[i].second] += right_picked;
             tmp.push_back(idx_arr[i++]);
          }
       }

       while(i < mid)
       {
         //ans 不是只在这一层更新的
         //ans[i] 在每一层递归的 merge 里都会累加贡献。
         ans[idx_arr[i].second] += right_picked;
         tmp.push_back(idx_arr[i++]);
       }

       while(j < r)
         tmp.push_back(idx_arr[j++]);

       for (int k = l; k < r; k++)
         // tmp 被塞满了 从 [l, mid) 与 [mid, r)的所有元素
         // 所以 r-1-l 不是越界 
         idx_arr[k] = tmp[k-l];
       
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);

        //构建 value, original_idx 数组
        vector<pair<int, int>> idx_arr(n);
        for (int i = 0; i < n; i++)
          idx_arr[i] = {nums[i], i};
        
        // [0, n)
        mergeSort(idx_arr, 0, n);
        return ans;
    }
};