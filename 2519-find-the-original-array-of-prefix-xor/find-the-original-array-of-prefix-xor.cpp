class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        if (pref.empty())
          return {};
        
        int n = pref.size();

        vector<int> nums(n, 0);
        nums[0] = pref[0];
        for (int i = 1; i < n; i++)
          nums[i] = pref[i] ^ pref[i-1];

        return nums; 
    }
};