class Solution {
public:
 
    vector<int> origin;
    vector<int> curr;
    Solution(vector<int>& nums) {
        origin = nums;
        curr = nums;
        srand(time(nullptr));
    }
    
    vector<int> reset() {
        curr = origin;
        return curr;
    }
    
    vector<int> shuffle() {
        int n = curr.size();
        for (int i = n - 1; i > 0; i--)
        {
          int j = rand() % (i + 1);  // j 是 [0, i] 中的一个数字
          swap(curr[i], curr[j]);
        }

        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */