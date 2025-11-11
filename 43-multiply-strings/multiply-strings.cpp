class Solution {
public:
    string multiply(string num1, string num2) {
         
         int n = num1.size();
         int m = num2.size();

         string res;
         if (n<= 0 || m <=0)
           return res;

        if (num1 == "0" || num2 == "0")
          return "0";

        vector<int> finalProduct(m+n, 0);
        /* 
            1 2 3
              4 5
         --------
            6 1 5
          4 9 2 
         --------
        5  5  3  5    
        */    

        for (int i = n - 1; i >= 0; i--)
        {
            int num1_digit = num1[i] - '0'; 
            for (int j = m - 1; j >= 0; j--)
            {
               int num2_digit = num2[j] - '0';
               int product = num1_digit * num2_digit;

               int p1 = i + j;
               int p2 = i + j + 1;


               int sum =  finalProduct[p2] + product;
               finalProduct[p2] = sum % 10;
               finalProduct[p1] += sum/10;
            }
        }

        string ans;
        for (int i = 0; i < finalProduct.size(); i++)
        {
           if (finalProduct[i] == 0 && ans.empty())
             continue;
           
           ans += finalProduct[i] + '0';
        }

        return ans;
    }
};