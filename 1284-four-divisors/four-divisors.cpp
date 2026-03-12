class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int n = nums.size();
        int res = 0;
        for (int num : nums)
        {
          int sum = 0;
          int cnt = 0;
          for (int i = 1; i * i <= num; i++)
          {
              if ((num % i) != 0)
                continue;
            
              sum += i;
              cnt++;

              if (i != num/i)
              {
                sum += num/i;
                cnt++;
              }

              if (cnt > 4)
                break;
          }
          
          //所有都是 4个divisor的数
          if (cnt == 4)
            res += sum;
        }
        return res;
    }
};