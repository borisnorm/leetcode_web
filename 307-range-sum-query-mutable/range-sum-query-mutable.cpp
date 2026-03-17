class NumArray {
public:
    vector<int> bit;
    vector<int> orig;
    int n;

    int lowbit(int x)
    {
      return x & (-x);
    }

    void add(int idx, int delta)
    {
      while (idx <= n)
      {
        bit[idx] += delta;
        idx += lowbit(idx);
      }
    }
    int prefixSum(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
           sum += bit[idx];
           idx -= lowbit(idx);
        }

        return sum;
    }
    NumArray(vector<int>& nums) {
       n = nums.size();
       bit.assign(n+1, 0);
       orig = nums;
       for (int i = 0; i < n; i++)
         add(i+1, orig[i]);
    }

    void update(int index, int val) {
        int diff = val - orig[index];
        orig[index] = val;
        add(index+1, diff);
    }

    int sumRange(int left, int right) {
      return prefixSum(right+1) - prefixSum(left);
    }
};
/*
class NumArray {
public:
    vector<int> prefixSum;
    vector<int> orig;
    int maxLen = 0;
    NumArray(vector<int>& nums) {
       int n = nums.size();
       prefixSum.assign(n+1, 0);
       orig = nums;

       maxLen = n;
       for (int i = 0; i < n; i++)
       {
         prefixSum[i+1] = prefixSum[i] + nums[i];
       }
    }
    
    void update(int index, int val) {
      // prefix[idx] 
      int delta = val - orig[index];
      orig[index] = val;
      for (int i = index; i < maxLen; i++)
      {
        prefixSum[i+1] += delta;
      }
    }
    
    // [i+1, right]
    int sumRange(int left, int right) {
        if (left < 0 || right + 1 > maxLen)
          return -1;
       return prefixSum[right+1] - prefixSum[left];
       // return prefixSum[right]- prefixSum[left-1];
    }
};

*/
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */