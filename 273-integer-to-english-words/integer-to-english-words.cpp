class Solution {
public:

   vector<string> below_10 = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

   vector<string> below_20 = {
     "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" 
   };

   vector<string> below_100 = {
    "",  "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

   string helper(int num){
       if (num == 0)
         return "";

       if (num < 10)
         return below_10[num] + " ";

       if (num < 20)
         return below_20[num%10] + " ";

       if (num < 100)
         return below_100[num/10] + " " + helper(num%10);

       return below_10[num/100] + " Hundred" + " " + helper(num%100);
   }

    string numberToWords(int num) {
        if (num == 0)
          return "Zero";

        string res;
        long long base;

        base = 1000000000;
        if (num >= base)
        {
           int data = num / base;
           res += helper(data) + "Billion" + " " ;
           num = num % base;
        }    

        base = 1000000;
        if (num >= base)
        {
           int data = num / base;
           res += helper(data) + "Million" + " ";
           num = num % base;
        }

        base = 1000;
        if (num >= base)
        {
           int data = num / base;
           res += helper(data) + "Thousand" + " ";
           num = num % base;
        }

       if (num > 0)
         res += helper(num);


       if (!res.empty() && res.back() == ' ')
         res.pop_back();
    
       return res;


    }

};