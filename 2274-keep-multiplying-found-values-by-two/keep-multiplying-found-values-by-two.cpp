class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int target = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0; 
            int r = n;

            bool isFound = false;

            while (l < r)
            {
               int mid = l + (r - l)/2;
               
               if (nums[mid] < original)
                  l = mid + 1;
               else if (nums[mid] > original)
                  r = mid;
               else
               {
                  isFound = true;
                  break;
               }
            }

            if (!isFound)
              break;
            
            original = original * 2;
        }

        return original;
    }
};