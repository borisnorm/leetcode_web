class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
          return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;
        vector<int> cols(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
               if (matrix[i][j] == '1')
                 cols[j] += 1;
               else
                 cols[j] = 0;
            }

             int area = getMaxArea(cols);
              maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int getMaxArea(vector<int>& nums)
    {
       int n = nums.size();

       stack<int> st;

       long long maxArea = 0;

       for (int i = 0; i <= n; i++)
       {
          int curH = (i < n) ? nums[i] : 0;

          while(!st.empty() && curH < nums[st.top()])
          {
              int r = i;
              int cur = st.top();
              st.pop();
              int l = (st.empty()) ? - 1: st.top();

              long long w = r - l - 1;
              long long h = nums[cur];
              long long area = w * h;

              maxArea = max(maxArea, area);
          }

          st.push(i);
       }

       return (int)maxArea;
    }
};
/*
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
          return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);

        int maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            int cur_left = 0;
            int cur_right = n;

            for (int j = 0; j < n; j++)
            {
              if (matrix[i][j] == '1')
                height[j] +=1;
              else
                height[j] = 0;
            }

            for (int j = 0; j < n; j++)
            {
               if (matrix[i][j] == '1')
                 left[j] = max(left[j] , cur_left);
               else
               {
                  left[j] = 0;
                  cur_left = j + 1;
               }
            }

            for (int j = n - 1; j>=0; j--)
            {
              if (matrix[i][j] == '1')
                right[j] = min(right[j], cur_right);
              else
              {
                right[j] = n;
                cur_right = j;
              }
            }

            for (int j = 0; j < n; j++)
            {
              int width = right[j] - left[j];
              int area  = height[j] * width;

              maxArea = max(maxArea, area);
            }
        }

        return maxArea;

    }
};

*/