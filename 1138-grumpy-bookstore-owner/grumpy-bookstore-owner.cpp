class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int base = 0;

        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
              base += customers[i];
        }

        // windowCustomer
        int windowCust = 0;
        int maxWinCust = 0;
        for (int i = 0; i < minutes; i++)
        {
           if (grumpy[i] == 1)
             windowCust += customers[i];
        }
        maxWinCust = windowCust;

        for (int r = minutes; r < n; r++)
        {
           if (grumpy[r] == 1)
             windowCust += customers[r];
           
           int l = r - minutes;
           if (grumpy[l] == 1)
             windowCust -= customers[l];
          
           maxWinCust = max(maxWinCust, windowCust);
        }

        return base + maxWinCust;

    }
};