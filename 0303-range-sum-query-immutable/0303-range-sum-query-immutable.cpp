class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        this->preSum = nums;

        for (int i = 0 ; i < nums.size(); i++)
          preSum[i] = ((i==0) ? 0: preSum[i-1]) + nums[i];
    }
    
    int sumRange(int left, int right) {
        int result;
        if (right > preSum.size() || left < 0)
          return INT_MAX; 
        result = preSum[right] - ((left == 0) ? 0: preSum[left-1]);

        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */