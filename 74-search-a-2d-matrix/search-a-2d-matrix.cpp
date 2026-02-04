class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        if (m <=0 )
          return false;
        int n  = matrix[0].size();
        if (n <=0)
           return false;

        int left = 0;
        int right = m*n -1;

        // 把 2D 的 matrix flatten 成 1D 的数组
        // 关键是 获取 1D 转 2D 的 val
        // mid/n 表示行  mid%n 表示列
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            int value = matrix[mid/n][mid%n];

            if (value > target )
              right = mid - 1;
            else if (value < target )
              left = mid + 1;
            else
              return true;
        }

        return false;


    }
};