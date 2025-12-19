class Solution {
public:

 int sumSubarrayMins(vector<int>& arr) {
      const long long MOD = 1'000'000'007LL;
      int n = (int)arr.size();

      vector<int> ple(n);
      vector<int> nle(n);

      stack<int> st;
      for (int i = 0; i < n; i++)
      {
          int v = arr[i];
          while (!st.empty() && arr[st.top()] >= arr[i])
          {
             st.pop();
          }
          // 求的是 arr[k] < arr[i] 
          //设 j = ple[i]，它是左边最近的 < arr[i] 的位置。
          ple[i] = st.empty() ? -1 : st.top();

          st.push(i);
      }

      while (!st.empty()) st.pop();
      for (int i = n - 1; i >= 0; i--)
      {
         int v = arr[i];
         while (!st.empty() && arr[st.top()] > arr[i])
          st.pop();

        // 求的是 arr[k] <= arr[i] 中的 k 是右边界
        nle[i] = st.empty() ? n : st.top();  

         st.push(i);
      }

      long long res = 0;
      for (int i = 0; i < n; i++)
      {
         long long left = i - ple[i];   // left=i−(ple[i]+1)+1=i−ple[i]
         long long right = nle[i] - i;  // right=(nle[i]−1)−i+1=nle[i]−i

         long long contrib = ((long long)arr[i] * left) % MOD;
         contrib = (contrib * right) % MOD;
         res  =  (res + contrib) % MOD; 
      }

      return res;

 }
    /*
    // 超时 and Memory Limite exceed
    int sumSubarrayMins(vector<int>& arr) {
        

        vector<vector<long long>> subarr_comb;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
           vector<long long> subarr;
           for (int j = i; j < n; j++)
           {
              subarr.push_back((long long)arr[j]);
              subarr_comb.push_back(subarr);
           }
        }

        long long sum = 0;
        for (auto& subarr: subarr_comb)
        {
           long long minVal = INT_MAX;
           for (auto x: subarr)
             minVal = min(minVal, (long long)x);
        
           sum += minVal;
        }

       return sum;

    }

    */
};