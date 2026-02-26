class Solution {
public:
   bool find132pattern(vector<int>& nums) {
       int n = nums.size();

       if (n < 3)
         return false;
       

       // 132 pattern 的 意思 1st < 3rd < 2nd
       // 不是  1 < 3 < 2, 不是 数字上的按个意思
       // 1 3 2  是 val 的上比较, 按照 i , j, k 排序即可, i 1st, j 2nd, k 3rd 即可
       // 也就是 num[j]最大
       stack<int> st; 
       int second = INT_MIN;
       for (int i = n  - 1; i >= 0; i--)
       {
           // 当前 i 是 num_1st, 当前 second 是旧值 
           if (nums[i] < second)
             return true;

          // 单调递减栈, 当前 num[i]是 num_3rd, st.top()是 num_end               
          while (!st.empty() && nums[i] > st.top())
          {
             second = st.top();
             st.pop();
          }

          st.push(nums[i]);
       }

       return false;
   }


   /*
   // 超时
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (nums[j] > nums[i])
                {
                  for (int k = j + 1; k < n; k++)
                  {
                     if (nums[j] > nums[k] && nums[i] < nums[k])
                        return true;
                  }
                }
            }
        }

        return false;
    }
    */
};

//错误的 case
/*
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 1 2 3
        // 单调递增,  1 3 2, 仅仅只是  1, 3, 

        int n = nums.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
           while (!st.empty() && nums[i] < nums[st.top()])
           {
              int num_3rd = nums[i];             // k
              int num_2nd = nums[st.top()];      // j
              st.pop();
              int num_1st = !st.empty()? nums[st.top()] : INT_MAX;  // i

              // 符合题意要求, 
              // nums[i] < nums[k] < nums[j]
              // 但不符合 测试 case [3,5,0,3,4],   [3, 5, 0] 首先就返回了 false
              // 但 [3, 5, 4] 却 应该是 true
              // 但单调递增后 3, 5, 0 后, 栈里面只有 0 存在了, 3, 5 就被出栈抛弃了
              // 所以 [0, 3, 4] 这个 单调递增的序列里 没有找到 [3, 5, 4]这个解
              if (num_1st < num_3rd && num_3rd < num_2nd)
                return true;

           }
           st.push(i);
        }

        return false;
    }
};

*/