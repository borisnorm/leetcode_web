class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int d5_cnt = 0;
        int d10_cnt = 0;
        int d20_cnt = 0; 

        for (int bill: bills)
        {
            if (bill == 5)
              d5_cnt++;
            else if (bill == 10)
            {
               if (d5_cnt > 0)
                 d5_cnt--;
               else
                 return false;

               d10_cnt++;
            }
            else if (bill == 20)
            {
               int change = bill - 5;
               //3* 5 = 10 + 5,  

               if (d10_cnt > 0 && d5_cnt > 0)
               {
                  d10_cnt--;
                  d5_cnt--;
               }
               else if (d5_cnt >= 3)
               {
                  d5_cnt -= 3;
               }
               else
               {
                  return false;
               }
                 
               d20_cnt++;
            }
        }

        return true;
    }
};