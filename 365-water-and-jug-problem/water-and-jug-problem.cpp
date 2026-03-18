class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target == 0)
          return false;
        
        if (target > x + y)
          return false;

        return target % gcd(x, y) == 0;
    }

    //辗转相除法
    int gcd2(int a, int b)
    {
      while (b != 0)              // b 不为 0 就继续
      {
        int tmp = a % b;        // 求余数
        a = b;                  // a 换成 b
        b = tmp;                // b 换成余数
      }
      return a;                   // b=0 时 a 就是答案
   }
};