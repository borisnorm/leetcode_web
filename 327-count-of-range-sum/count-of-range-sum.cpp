class Solution {
public:
    int lower_g;
    int upper_g;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lower_g = lower;
        upper_g = upper;

        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for (int i = 0; i < n; i++)
          pre[i+1] = pre[i] + nums[i];
        
        return mergeSort(pre, 0, n+1);
    }

    int mergeSort(vector<long long>& pre, int l, int r)
    {
      if (r-l <= 1)
        return 0;
      
      int mid = l + (r-l)/2;
      int cnt = mergeSort(pre, l, mid) + mergeSort(pre, mid, r);

      int lo = mid;
      int hi = mid;

      for (int i = l; i < mid; i++)
      {
         while (lo < r && pre[lo] < (long long)pre[i] + lower_g)
           lo++;
        
         while (hi < r && pre[hi] <= (long long)pre[i] + upper_g)
           hi++;
        
         cnt += hi-lo;
      }

      vector<long long> tmp;
      int a = l;
      int b = mid;
      while (a < mid && b < r)
      {
        if (pre[a] <= pre[b])
          tmp.push_back(pre[a++]);
        else
          tmp.push_back(pre[b++]);
      }

      while(a < mid)
        tmp.push_back(pre[a++]);
    
      while (b < r)
        tmp.push_back(pre[b++]);
    
      for (int i = l; i < r; i++)
        pre[i] = tmp[i-l];  //写回
     
      return cnt;
    }
};