class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
          return 0;

        int n = nums.size();

        // 下一个可以写入的位置
        int write = 1;
        
        // 对于重复的 值, 只保留第一个, 所以 write[0] 被保留下来
        // [0, , write-1] 表示已经去重的元素 集合
        //  read 表示可能存在 的重复值
        for (int read = 1; read < n; read++)
        {
           if (nums[read] != nums[write-1])
           {
              nums[write++] = nums[read];
           }
        }

        return write;
    }
};