class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

          if (nums.empty())
            return {};
   
          int n = nums.size();

          vector<int> res(n, -1);
          stack<int> st;

          for (int i = 0; i < 2*n; i++)
          {
             int idx = i % n;
             
             int v = nums[idx];
             while (!st.empty() && v > nums[st.top()])
             {
                int preIdx = st.top();
                res[preIdx] = v;
                st.pop();
             }
             
             if (idx < n)
               st.push(idx);
          }

          return res;
    }
};