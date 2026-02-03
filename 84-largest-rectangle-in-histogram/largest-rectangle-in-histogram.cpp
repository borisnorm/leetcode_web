class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int n  = heights.size();
          if (n == 0)
            return 0;
         
          // heights.push_back(0) 的作用是：
          // 强制把栈里所有还没结算面积的柱子，全部弹出来计算。
          //
          // heights = [2, 3, 4, 5]        [5, 6, 5, 5]
          // 结果
          // heights = [2, 3, 4, 5, 0]     [5, 6, 5, 5]
          //
          // 这是保证栈被情况的条件
          // 单调栈这题里有一个规则：
          // 只有“遇到更矮的柱子”时，栈顶柱子的面积才会被计算。
          heights.push_back(0);
          n++;

          stack<int> st;
          int maxArea = 0;

          for (int i = 0; i < n; i++)
          {
            //case:  [2, 1, 2]
            // 使用 if ... else.. 结构只能将 第一个2 钉死在 栈底的位置 
            //(1) heights[i] 就是栈底, 那这么设置, 这个栈就必然是 单调递增栈了
            //(2) 不进行 pop 的条件是 height[i] >= heights[st.top()], 还是单调递增栈的 
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int top = st.top();
                st.pop();

                //heights = [2,1,5,6,2,3,0]
                int h = heights[top];
                int left = st.empty() ? -1 : st.top();
                int right = i; 
                // righ -1 是因为 height[i] 是 < height[st.top()]的那一个
                // left + 1 是因为 上面 st.pop() 已经被 弹出一次, 现在的 st.top 是最左侧的
                // (left, right) 
                // right: 右边第一个 < heights[top] 的下标（就是 i）
                // left：左边第一个 < heights[top] 的下标（弹栈后的 st.top() 或 -1）
                // i 或者说 right 是 确定的了, 但是 left bound 在 一直 进行扩展
                // width = right - left - 1;   这是闭区间的取值长度 (left,right)
                // int width = (right - 1) - (left + 1 ) + 1; 
                int width = right - left - 1;
                int area = h * width;

                maxArea = max(maxArea, area);
            }
            st.push(i);
          }

          return maxArea;
    }
};