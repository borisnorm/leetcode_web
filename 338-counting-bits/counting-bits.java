class Solution {
    public int[] countBits(int n) {
        

        int[] res = new int[n+1];
        res[0] = 0;

        for (int i = 1; i <= n; i++)
        {
           int cnt = 0;
           int num = i;
           while (num > 0)
           {
              if ((num & 0x1) == 1)
                cnt++;
              num = num >> 1;
           }
         
           res[i] = cnt;
        }

        return res;
    }
}