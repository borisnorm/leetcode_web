class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetIdx = n - k;

        return quickSelect(nums, 0, n-1, targetIdx);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)
          return nums[l];
        
        int pivotIdx = partition(nums, l, r);

        if (pivotIdx == k)
          return nums[k];
        else if (pivotIdx > k)
          return quickSelect(nums, l, pivotIdx-1, k);
        else
          return quickSelect(nums, pivotIdx+1, r, k);
    }

    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[r]; //选最右边的元素作为 pivot
        int i = l; // i指向下一个小于 pivot 的元素应该放的位置

        //遍历[l, r-1] , 把小于 pivot的都移到左边
        for (int j = l; j < r; j++)
        {
            if (nums[j] < pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        //把pivot 放到正确的位置(所有小于它的元素之后)
        swap(nums[i], nums[r]);

        // 返回 pivot 的最终位置
        return i;
    }
};
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

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
          return -1;
        
        int n = nums.size();
        
        if (n < k)
          return -1;
        
        // 也可以这么初始化
        //  priority_queue<int> maxHeap(nums.begin(), nums.end());
        priority_queue<int> pq;
        for (int num: nums)
          pq.push(num);
        
        int kthLargest = 0;
        for(int i = 0; i < k; i++)
        {
            kthLargest = pq.top();
            pq.pop();
        }
        
        return kthLargest;        
    }
};
*/

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
          return -1;
        
        int n = nums.size();
        
        if (n < k)
          return -1;
        
        // 也可以这么初始化
        //  priority_queue<int> maxHeap(nums.begin(), nums.end());
        priority_queue<int> pq;
        for (int num: nums)
          pq.push(num);
        
        int kthLargest = 0;
        
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
*/