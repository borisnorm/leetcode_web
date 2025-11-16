class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int n  = heights.size();
          if (n == 0)
            return 0;

          heights.push_back(0);
          n++;

          stack<int> st;
          int maxArea = 0;

          for (int i = 0; i < n; i++)
          {
             while (!st.empty() && heights[i] < heights[st.top()])
            {
                int top = st.top();
                st.pop();

                int h = heights[top];
                int left = st.empty() ? -1 : st.top();
                int right = i; 
                int width = (right - 1) - (left + 1 ) + 1;
                int area = h * width;

                maxArea = max(maxArea, area);
            }
            st.push(i);
          }

          return maxArea;
    }
};