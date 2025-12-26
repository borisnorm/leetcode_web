class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //monolithc stack 

        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
           while (!st.empty() && arr[i] > arr[st.top()])
             st.pop();

           st.push(i);
        }

        int peakIdx = 0;
        while (!st.empty())
        {
           peakIdx = st.top();
           st.pop();
        }

        return peakIdx;
    }
};