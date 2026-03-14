class Solution {
public:
    char findKthBit(int n, int k) {
        
        // 返回 右边的 kth bit
        // 一层 一层 处理 n
        return dfs(n, k);
    }

    char dfs(int n, int k)
    {
       if (k == 1)
         return '0';
      
       //int len = 2^n - 1;
       int len = (1 << n) - 1;
       int mid = (len+1)/2; //1-based

       // mid 永远是 1
       if (mid == k)
       {
          return '1';
       }
       else if (k < mid)  // mid 是中间那个位置 '1', 不是 二分的那个 mid
       {
          return dfs(n-1, k);
       }
       else
       {
          int mirror = len + 1 - k;
          char c = dfs(n-1, mirror);
          return c == '0' ? '1' : '0';
       }
    }
};