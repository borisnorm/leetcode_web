class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        long long res = 0;
        stack<int> st;
        st.push(INT_MAX);

        for (int num : arr)
        {
            //单调递减
            while(!st.empty() && num >= st.top())
            {
               int mid = st.top();
               st.pop();
               int leftGreater = st.top();

               int best = min(leftGreater, num);
               res += 1LL * mid * best;
            }

            st.push(num);
        }

        while (st.size() > 2)
        {
            int mid = st.top();
            st.pop();
            res += 1LL * mid * st.top();
        }

        return (int)res;
    }
};