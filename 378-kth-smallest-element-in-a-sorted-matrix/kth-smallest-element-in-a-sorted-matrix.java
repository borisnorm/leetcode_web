class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;

        long l = matrix[0][0];
        long r = matrix[n-1][n-1];

        while (l < r)
        {
           long mid = l + (r-l)/2;

           if (countLessEqual(matrix, mid) < k)
             l = mid + 1;
           else
             r = mid; 
        }

        return (int)l;
    }

    public int countLessEqual(int[][] matrix, long target)
    {
        int n = matrix.length;

        int r = 0;
        int c = n - 1;

        int cnt = 0;
        while (r < n && c >=0)
        {
            if (matrix[r][c] <= target)
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
}