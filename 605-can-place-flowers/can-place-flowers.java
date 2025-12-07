class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
         int sz = flowerbed.length;

         for (int i = 0; i < sz; i++)
         {
            if (flowerbed[i] == 1)
              continue;

            int left =  (i == 0)      ? 0 : flowerbed[i-1];
            int right = (i == sz - 1) ? 0 : flowerbed[i+1];

            if (left == 0 && right == 0 && flowerbed[i] == 0)
            {
               flowerbed[i] = 1;
               n--;
            } 
         }

         return (n > 0) ? false : true;
    }
}