class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return mergeSort(nums, 0, n);
    }

    int mergeSort(vector<int>& nums, int l, int r)
    {
      //只有1个元素, 没有 pair
      if (r - l <= 1)
        return 0;

      int mid = l + (r-l)/2;

      int cnt = mergeSort(nums, l, mid) + mergeSort(nums, mid, r);

      for (int i = l, j = mid; i < mid; i++)
      {
         while (j < r && (long long)nums[i] > 2LL * nums[j])
           j++;
         
         cnt += j - mid;
      }

      vector<int> tmp;
      int i = l;
      int j = mid;

      while (i < mid && j < r)
      {
          if (nums[i] <= nums[j])
          {
            tmp.push_back(nums[i]);
            i++;
          }
          else
          {
            tmp.push_back(nums[j]);
            j++;
          }
      }

      while (i < mid)
        tmp.push_back(nums[i++]);

      while (j < r)
        tmp.push_back(nums[j++]);

      for (int i = l; i < r; i++)
        nums[i] = tmp[i-l];

      return cnt;
    }
};