class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        //             - front
        //           -
        //         -
        // tail  -
        deque<int> maxQ; //单调递减, 队头始终是窗口最大值, 存下标
        //  tail -
        //         -
        //           -
        //             -
        //               - front
        deque<int> minQ; //单调递增, 队头始终是窗口最小值, 存下标

        int l = 0;
        int res = 0;

        for (int r = 0; r < nums.size(); r++)
        {
           // 已 back 为top,  front为底 maxQ 就是单调递减 栈
           while (!maxQ.empty() && nums[r] >= nums[maxQ.back()])
             maxQ.pop_back();
           maxQ.push_back(r);

          while (!minQ.empty() && nums[r] <= nums[minQ.back()])
            minQ.pop_back();
          minQ.push_back(r);

          while (nums[maxQ.front()] - nums[minQ.front()] > limit)
          {
            l++;
            if (maxQ.front() < l)
              maxQ.pop_front();
            
            if (minQ.front() < l)
              minQ.pop_front();
          }
          res = max(res, r - l + 1);
        }
        return res;
    }
};