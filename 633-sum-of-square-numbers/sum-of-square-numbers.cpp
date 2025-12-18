class Solution {
public: 
  bool judgeSquareSum(int c) {
      if (c <= 1)
        return true;

      long long l = 0;
      long long r = (long long)sqrt(c);
      while (l <= r)
      {
         long long sum = l * l + r * r;

         if (sum < c)
           l++;
         else if (sum > c)
           r--;
         else
           return true;
      }

      return false;
  }
/*
    bool judgeSquareSum(int c) {
        
        unordered_set<long long> squares;
        for (long long i = 0; i*i <= c; i++)
        {
          long long target = c - i*i;
          if ((target == i*i) || squares.count(target))
            return true;
          
          squares.insert(i*i);
        }

        return false;
    }
*/
};