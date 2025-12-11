class Solution {
public:
    vector<int> grayCode(int n) {
        
        
        vector<int> res;
        res.push_back(0);
        if (n == 0)
          return res;

       // G(n) = G(n-1) + reverse(G(n-1)) with highest bit = 1
    
       for (int i = 1; i <= n; i++)
       {
          int prefix = 1 << (i-1);
          int size = res.size();
          
          for (int j = size - 1; j >= 0; j--)
             res.push_back(res[j] | prefix);
       }
        
        return res;
    }


    /*
    vector<int> grayCode(int n) {
        
        int size = 1 << n;
        vector<int> res(size);
        // gray[i] = i ^ (i >> 1);
        for (int i = 0; i < size; i++)
          res[i] = i ^ (i >> 1);
        
        return res;
    }
    */
};