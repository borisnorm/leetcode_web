class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // 大顶堆
        
        if (nums.empty())
          return 0;

        priority_queue<int, vector<int>, greater<int>> nums_pq;  //小顶堆

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
           nums_pq.push(nums[i]);
           if (nums_pq.size() > k)
             nums_pq.pop(); 
        }

        return nums_pq.top();
    }
};