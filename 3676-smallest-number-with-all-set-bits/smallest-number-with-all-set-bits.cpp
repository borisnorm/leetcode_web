class Solution {
public:
    int smallestNumber(int n) {
          int target = 1;

          while (target < n)
          {
             target = (target << 1) | 0x1; 
          }

          return target;
    }
};