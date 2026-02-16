class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
          int n = nums.size();
          if (n < k)
            return  "";
          int targetIdx = n - k;
        
         int l = 0;
         int r = n -1;
         while (l <= r)
         {
            int pivotIdx = l + rand() % (r-l+1);
            string pivot = nums[pivotIdx];

            int lt = l;
            int i = l;
            int gt = r;

            while (i <= gt)
            {
        
               if (lessThan(nums[i], pivot))
                 swap(nums[i++], nums[lt++]);
               else if (lessThan(pivot, nums[i]))
                 swap(nums[i], nums[gt--]);
               else
                 i++;
            }

            if (targetIdx < lt)
              r = lt - 1;
            else if (targetIdx > gt)
              l = gt + 1;
            else
              return nums[targetIdx];
         }

         return "";
    }

    bool lessThan(const string& a, string& b)
    {
        if (a.size() != b.size())
         return a.size() < b.size();
        else
        {
          return a < b;
        }
    }
};