class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        if (num == 0)
          return false;

        unordered_set<int> divisors;
        for (int i = 1; i < num; i++)
          if (num % i == 0)
            divisors.insert(i);
    
     
        int sum = 0;
        for (auto& it: divisors)
        {
           sum += it;
        }

        if (sum == num)
          return true;

        return false;

    }
};