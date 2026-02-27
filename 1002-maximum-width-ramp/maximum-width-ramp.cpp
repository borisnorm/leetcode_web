class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        stack<int> st; // monolithic decrease

        // i1 < i2  单调递减, 过滤掉 i2,  i1 支配 dominance 了 i2
        for (int i = 0; i < n; i++)
        {
           if (st.empty() || nums[i] < nums[st.top()])
             st.push(i);
        }

        int maxWidth = 0;
        for (int j = n - 1; j >= 0; j--)
        {
           while (!st.empty() && nums[j] >= nums[st.top()])
           {
              int width = j - st.top();
              st.pop();
              maxWidth = max(maxWidth, width);
           }
        }

        return maxWidth;
    }
};