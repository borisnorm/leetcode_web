class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
         int n = arr.size();

        //[0, l]  递增 , 可以删除 [l+1, n-1]
        int l = 0;
         while (l + 1 < n && arr[l] <= arr[l+1])
           l++;

        if (l == n - 1)
          return 0;
          
        // [r, n-1] 递增, 可以删除 [0, r-1]
        int r = n - 1;  
        while (r-1 >= 0 && arr[r-1] <= arr[r])
          r--;
        
        int minLen = min(n-1-l, r);

        int l2 = 0;
        int r2 = r;

        while (l2 <= l && r2 < n)
        {
           if (arr[l2] <= arr[r2])
           {
              //可以执行到这里, 也就是说 [l2+1, r2-1] 可以删除
              minLen = min(minLen, r2-l2-1);
              l2++;
           }
           else
           {
               r2++;
           }
        }

        return minLen;
    }
};