class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
          return {};
      
        int n = nums.size();
        deque<int> dq; // index dequeue
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
          //[i−k+1,i] 是 对于 i 这个位置 大小为 k 的 window
          // 当队列 front 的 index < 当前的 leftmost index 时候
          // pop 的作用主要是为了保证窗口正确性，而不是单纯维持大小 
          if (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();

          //  维护单调递减, 然后 dq.front 就是这个 window 的最大值
          while (!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();

          dq.push_back(i);
          
          // k 是 1-based, 要转换成 0-based
          // 否则 i < k - 1的时候, window 还没有形成
          if (i >= k - 1)
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};