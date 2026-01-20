/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        int l = 0;
        int r = n;
        
        while (l <= r)
        {
           long long mid = l + (r - l)/2;

           int ans = guess(mid);
           if (ans == 0)
             return mid;
           else if (ans == - 1)
             r = mid - 1;
           else if (ans == 1)
             l = mid + 1;
        }  

        return -1;
    }
/*
    int guessNumber(int n) {

       int i = 1;
       while (i <= n)
       {
          if (guess(i) == 0)
            return i;
          else if (guess(i) == -1)
            i--;
          else if (guess(i) == 1)
            i++;
       }

       return i;
    }
*/
};