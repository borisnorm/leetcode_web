class Solution {
public:

    bool canMake(int machineIdx, long long x,
                 const vector<vector<int>>& comp,
                 const vector<int>& stock,
                 const vector<int>& cost,
                 long long budget)
    {

      long long spend = 0;
      int n = comp[machineIdx].size();

      for (int j = 0; j < n; j++)
      {
         long long need = (long long)comp[machineIdx][j] * x;
         long long lack = max(0LL, need-stock[j]);

         spend += lack * cost[j];

         if (spend > budget)
           return false;
      }

      return true;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        
        int ans = 0;

        for (int i = 0; i < k; i++)
        {
           long long lo = 0;
           long long hi = 1'000'000'000LL;

           while (lo < hi)
           {
              long long mid = lo + (hi - lo + 1) / 2;
              if (canMake(i, mid, composition, stock, cost, budget))
                lo = mid;
              else
                hi = mid - 1; 
           }

           ans = max(ans, (int)lo);
        }

        return ans;
    }
};