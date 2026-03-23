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
        int windowCustCnt = 0;
        int maxWinCustCnt = 0;
        for (int i = 0; i < minutes; i++)
        {
           if (grumpy[i] == 1)
             windowCustCnt += customers[i];
        }
        maxWinCustCnt = windowCustCnt;

        for (int r = minutes; r < n; r++)
        {
           if (grumpy[r] == 1)
             windowCustCnt += customers[r];
           
           int l = r - minutes;
           if (grumpy[l] == 1)
             windowCustCnt -= customers[l];
          
           maxWinCustCnt = max(maxWinCustCnt, windowCustCnt);
        }

        // minutes 内可以修复 grumpy的老板,所以取的最大数量
        return base + maxWinCustCnt;

    }
};