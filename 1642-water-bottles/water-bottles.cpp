class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        if (numBottles == 0)
          return 0;
        if (numExchange == 0)
          return numBottles;

        int totalDrinkCnt = 0;
        int drinkCnt = 0;
        int remain = 0;
        int newFullCnt = 0;
        while (numBottles)
        {
           // drink all
           drinkCnt = numBottles;
           totalDrinkCnt += drinkCnt;
           
           newFullCnt = (drinkCnt + remain) / numExchange;
           remain     = (drinkCnt + remain) % numExchange;

           numBottles = newFullCnt;
        }

        return totalDrinkCnt;
    }
};