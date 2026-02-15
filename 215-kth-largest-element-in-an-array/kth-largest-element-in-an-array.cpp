/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //这是小顶堆的解法
        if (nums.empty() || k <= 0)
          return -1;

        priority_queue<int, vector<int>, greater<int>> nums_pq;  //小顶堆
        int n = nums.size();
        if (n < k)
          return -1;
        for (int i = 0; i < n; i++)
        {
           nums_pq.push(nums[i]);
           if (nums_pq.size() > k)
             nums_pq.pop(); 
        }

        return nums_pq.top();
    }
};
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
          return -1;
        
        int n = nums.size();
        
        if (n < k)
          return -1;
        
        priority_queue<int> pq;
        for (int num: nums)
          pq.push(num);
        
        int kthLargest = 0;
        /*
        for(int i = 0; i < k; i++)
        {
            kthLargest = pq.top();
            pq.pop();
        }
        */

        //pq 没有 for-range的用法
        // 使用正常的 sz loop
        int cnt = 0;
        int q_sz = pq.size();
        for (int i = 0; i < q_sz; i++)
        {
            kthLargest = pq.top();
            pq.pop();
            cnt++;

            if (cnt == k)
              break;
        }
        return kthLargest;        
    }
};