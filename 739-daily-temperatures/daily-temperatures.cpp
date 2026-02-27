class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        if (temperatures.empty())
          return {};

        int n = temperatures.size();
        vector<int> res(n, 0);
 
        stack<int> st;
        for (int i = 0 ; i < n; i++)
        {
           while(!st.empty() && temperatures[i] > temperatures[st.top()] )
           {
              int preIdx = st.top();
              st.pop(); 

              res[preIdx] = i - preIdx;
           }

           st.push(i);
        }
        
        return res;
    }
};