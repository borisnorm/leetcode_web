class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
          return 0;
        
        int n = nums.size();

        // [0, slow), slow is next avail write pos
        // slow - 1 是 最后一个合法位置
        int slow = 1;
        //fast 从哪开始，取决于：“有没有一部分元素在一开始就已经被处理/确认过了”
        // 根据题意nums[0] 已经处理完了 fast 要从下一个开始
        for (int fast = 1; fast < n; fast++)
        {
           if (nums[fast] != nums[slow-1])
           {
              nums[slow] = nums[fast];
              slow++;
           }
        }
        return slow;
    }
};
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
          return 0;

        int n = nums.size();

        // write 主要用于指向下一个可以写入的位置
        // 那 write 的前一个元数据就是 i 对比的对象
        int write = 1;
        
        // 对于重复的 值, 只保留第一个, 所以 write[0] 被保留下来
        // [0, , write-1] 表示已经去重的元素 集合
        //  read 表示可能存在 的重复值
        for (int read = 1; read < n; read++)
        {
           // write-1 指向的是 最后一个 合法的元素
           // [0, write-1]
           // 而 write 在这个题的语义是指向下一个可写入的位置
           if (nums[read] != nums[write-1])
           {
              nums[write++] = nums[read];
           }
        }

        return write;
    }
};

*/