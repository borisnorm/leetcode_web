class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

            if (pushed.empty() && popped.empty())
              return true;

            stack<int> st;

            int j = 0;
            int n = popped.size();
            for (int x: pushed)
            {
               st.push(x);

               while(!st.empty() && j < n && st.top() == popped[j])
               {
                  st.pop();
                  j++;
               }
            } 

            return st.empty();
    }
};