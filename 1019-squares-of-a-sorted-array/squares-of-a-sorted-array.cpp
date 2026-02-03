class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0;
        int r = n -1;
        int write = n - 1;
        vector<int> res(n);

        while (l <= r)
        {
           int l_sqr = nums[l] * nums[l];
           int r_sqr = nums[r] * nums[r];

           if (l_sqr <= r_sqr)
           {
              res[write--] = r_sqr;
              r--; 
           }
           else
           {
              res[write--] = l_sqr;
              l++;
           }
        }

        return res;

    }
};

/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        if (nums.empty())
          return nums;
        
        int n = nums.size();
        int left = 0; 
        int right = n - 1;
        int pos = n - 1;

        vector<int> res(n);
       //  这个也是正确的 但不建议
        for (int i = 0; i < n; i++)
           nums[i] = nums[i]*nums[i];

        // 规律
        //[-5, 2, 1, 3]
        //[25, 4, 1, 9]
        //大的在两端, 小的在中间
        while (left <= right)
        {

           if (nums[left] <= nums[right])
           {
              res[pos] = nums[right];
              right--;
           }
           else
           {
              res[pos] = nums[left];
              left++;
           }
           pos--;
        }

        return res;
    }
};

*/