class Solution {

public int[] twoSum(int[] nums, int target) {

    int n = nums.length;

    int[][] num_vec = new int[n][2];

    int[] res = new int[2];
    for (int i = 0 ; i < n; i++)
    {
       num_vec[i][0] = nums[i];
       num_vec[i][1] = i;
    }

    Arrays.sort(num_vec, (a, b) -> Integer.compare(a[0], b[0]));

    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        long sum = num_vec[l][0] + num_vec[r][0];

       if (sum < target) 
         l++;
       else if (sum > target)
         r--;
       else
       {
          int l_idx = num_vec[l][1];
          int r_idx = num_vec[r][1];

          //if (l_idx > r_idx)
          //  swap(l_idx, r_idx);
        
          res[0] = l_idx < r_idx ? l_idx : r_idx;
          res[1] = l_idx > r_idx ? l_idx : r_idx;
          return res;
       }
    }

    return res;
}
/*
    public int[] twoSum(int[] nums, int target) {

       //错误的
       //HashMap<int, int>
       HashMap<Integer, Integer> num2idx = new HashMap<>();

       int n = nums.length;

      // int[] res = new int[2];

       // 错误的
       //int res[2];
       // 错误的
       //int[2] res;
       for (int i = 0; i < n; i++)
       {
         int remain = target - nums[i];
         if (num2idx.containsKey(remain))
         {
            res[0] = num2idx.get(remain);
            res[1] = i;
            return res;
         }

         num2idx.put(nums[i], i);
       }

       return res;
    }
*/

}