class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

         if (n == 0)
           return true;

         if (flowerbed.empty())
           return false;

        int len =  flowerbed.size();
        
         for (int i = 0; i < len; i++)
         {
            if (flowerbed[i] == 1)
              continue;
            
            int left = (i == 0) ? 0 : flowerbed[i-1];
            int right = (i == len -1 ) ? 0 : flowerbed[i+1];

            if (left == 0 && right == 0 && flowerbed[i] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
         }

         return (n > 0) ? false : true;
    }
};