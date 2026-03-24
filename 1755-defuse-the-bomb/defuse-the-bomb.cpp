class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        
        if (k == 0)
          return res;
        
        // [l, r]
        int l = (k > 0) ? 1 :  k + n;
        int r = (k > 0) ? k : -1 + n;

        int winSum = 0;
        // init the first window
        //初始化第一个窗口的和（对应 i=0）
        for (int i = l; i <= r; i++)
           winSum += code[i % n];
        
        for (int i = 0; i < n; i++)
        {
            res[i] = winSum;

            winSum += code[(r+1)%n];
            winSum -= code[l % n];
            l++;
            r++;
        }

        return res;
    }
};