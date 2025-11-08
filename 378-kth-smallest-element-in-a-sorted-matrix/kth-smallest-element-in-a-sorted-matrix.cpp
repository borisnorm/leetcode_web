class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         int n = matrix.size();
         if (n <= 0)
           return INT_MAX;
        
        int arr_size = n * n;

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while (low < high)
        {
           long long mid = low + (high-low)/2;
           int cnt = countLessthan(matrix, mid);
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