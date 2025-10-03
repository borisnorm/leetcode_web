class NumArray {
public:
    vector<int> nums_arr;
    NumArray(vector<int>& nums) {
      nums_arr = nums;   
    }
    
    int sumRange(int left, int right) {
      
        int sum = 0;
        if (left < 0 || right > nums_arr.size())
          return INT_MAX;
        
         while (left <= right)
         {
            sum+=nums_arr[left];
            left++;
         }
         
         return sum;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */