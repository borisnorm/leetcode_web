class Solution {
public:
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
};