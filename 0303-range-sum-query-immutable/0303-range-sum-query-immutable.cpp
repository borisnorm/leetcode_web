class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
      
        preSum.resize(nums.size()+1);
         
        for (int i = 0 ; i < nums.size(); i++)
          preSum[i+1] = preSum[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        int result;
        if (right > preSum.size() || left < 0)
          return INT_MAX; 
        result = preSum[right+1] - preSum[left];

        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */