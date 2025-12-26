class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
          return 0;

        sort(nums.begin(), nums.end());

        int maxPerim = 0;
        for (int i = n - 1; i - 2 >= 0; i--)
        {
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];
            if (a + b > c)
               return a + b + c;
        }

        return 0;
    }

    /*
      // 还是慢一点
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
          return 0;

        sort(nums.begin(), nums.end());

        int maxPerim = 0;
        for (int i = n - 1; i - 2 >= 0; i--)
        {
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];
            if (a + b > c)
               maxPerim = max(maxPerim, (a+b+c));
        }

        return maxPerim;
    }

    */


   /*
    int maxPerim = 0;
    vector<int> triangle;
    
    int largestPerimeter(vector<int>& nums) {
        
        // a + b > c
        int n = nums.size();
        if (n < 3)
          return 0;
        
        backtrack(nums, 0);

        return maxPerim;
    }

    void backtrack(vector<int>& nums, int pos)
    {
       int n = nums.size();

       if (triangle.size() == 3)
       {
          int sum = 0;
          int a = triangle[0];
          int b = triangle[1];
          int c = triangle[2];
          
          if (!((a+b>c) && (b+c > a) && (a+c > b)))
            return;
          
          sum = a + b +c;
          maxPerim = max(maxPerim, sum);
          return;
       }

       if (pos >= n)
         return;
       
       for (int i = pos; i < n; i++)
       {
          triangle.push_back(nums[i]);
          backtrack(nums, i + 1);
          triangle.pop_back();   
       }
       
    }
    */
};