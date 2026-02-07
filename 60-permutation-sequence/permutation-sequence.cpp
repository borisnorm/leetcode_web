class Solution {
public:
    string getPermutation(int n, int k) {
        
         if (k == 0)
           return "1";

         vector<int> nums(n, 0);
         for (int i = 0; i < n; i++)
           nums[i] = i + 1;

         /*
         for (int i = 1; i <= n; i++)
           nums[i-1] = i;
         */
        
         vector<int> fact(n, 1);
         for (int i = 1; i < n; i++)
           fact[i] = fact[i-1] * i;
        
         k--;
         string res = "";
         for (int i = n; i >= 1; i--)
         {
            int idx = k / fact[i-1];
            int num = nums[idx];
            res += to_string(num);
            nums.erase(nums.begin()+idx);

            k = k % fact[i-1];
         }

         return res;
    }
};


/*
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
          nums.push_back(i);
        
        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++)
          fact[i] = fact[i-1] * i;
        
        // 转换为0-based索引
        k--;

        string res = "";
        for (int i = n; i >= 1; i--)
        {
            int idx = k / fact[i-1];

            res += to_string(nums[idx]);
            nums.erase(nums.begin()+idx);

            k = k % fact[i-1];
        }
        
        return res;

    }
};

*/