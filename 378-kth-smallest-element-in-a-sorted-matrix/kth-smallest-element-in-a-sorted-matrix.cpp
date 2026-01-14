class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         int n = matrix.size();
         if (n <= 0)
           return INT_MAX;

        int low  = matrix[0][0];
        int high = matrix[n-1][n-1];

        // >= k 的第一个数
        while (low < high)
        {
           // mid 是 值域 范围[min, max] [maxtrix[0][0], matrix[n-1][n-1]] 中的一个数
           // 然后在 matrix 中 有多少数字 <= mid
           long long mid = 1LL*low + (1LL*high-low)/2;
           int cnt = countLessthan(matrix, mid);

           //count( matrix 中 <= x 的元素 ) >= k 
           if (cnt < k)
             low = mid + 1;
           else
             high = mid; 
        }

        return low; 

    }

    int countLessthan(vector<vector<int>>& matrix, long long mid)
    {

       int n = matrix.size();

       int r = 0;
       int c = n - 1;
    
       int cnt = 0;

       
      // 2) “上一行最后一个一定 ≤ mid” 不对：反例
     //考虑一行：
     //[1, 5, 9], mid = 6
    //从右上角 c=2 开始：
    //matrix[0][2] = 9 > 6 → c-- 到 1
    //matrix[0][1] = 5 <= 6 → 这时才 r++/
    //此时进入下一行的前提是：
    //✅ matrix[0][1] <= 6
    //但这一行最后一个元素是 matrix[0][2] = 9，明显 不是 ≤ mid。
    // 退出规则是 r++ 跳到下一行, 然后 c--直到 c < 0
       while (r < n && c >=0)
       {
          if (matrix[r][c] <= mid)
          {
              cnt += (c + 1);
              r++;     
          }
          else
          {
              c--;
          }
       }
       return cnt;
    }
};