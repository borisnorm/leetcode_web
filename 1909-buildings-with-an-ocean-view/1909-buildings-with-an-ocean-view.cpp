class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[i] >= heights[st.top()])
            {
                st.pop();
            }

            st.push(i);
        }

        vector<int> res;
        while(!st.empty())
        {
            int idx = st.top();
            st.pop();

            res.insert(res.begin(), idx);
        }

        return res;
    }
};