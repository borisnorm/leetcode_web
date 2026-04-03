class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
      vector<double> nums(cards.begin(), cards.end());

      return dfs(nums);
    }

    bool dfs(vector<double>& nums)
    {
       if (nums.size() == 1)
         return abs(nums[0] - 24.0) < 1e-6;
      
       int n = nums.size();

       for (int i = 0; i < n; i++)
       {
         for (int j = 0; j < n; j++)
         {
            if (i==j)
              continue;
            vector<double> next;
            for (int k = 0; k < n; k++)
            {
               if (k != i && k != j)
                 next.push_back(nums[k]);
            }

            double a = nums[i];
            double b = nums[j];
            for (double r : { a + b, a - b, a * b})
            {
               next.push_back(r);
               if (dfs(next))
                 return true;
               next.pop_back();
            }

            //防止 b 是 0
            if (abs(b) > 1e-6)
            {
               next.push_back(a/b);
               if (dfs(next))
                 return true;
               next.pop_back();
            }
         }
       }
       return false;
    }
};