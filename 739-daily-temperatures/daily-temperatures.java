class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        
        int n = temperatures.length;

        Stack<Integer> st = new Stack<Integer>();
        int[] res =  new int[n];

        for (int i = 0; i < n; i++)
        {
          while (!st.isEmpty() && temperatures[i] > temperatures[st.peek()])
          {
            int pre_idx = st.peek();
            st.pop();
            
            res[pre_idx] = i -  pre_idx;
          }

          st.push(i);
        }

        return res;
    }
}