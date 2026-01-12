class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> num2freq;
        unordered_set<int> num_set;
        //vector<int> res;
        int freq = nums.size()/3;
        for (int num: nums)
        {
           num2freq[num]++;
           if (num2freq[num] > freq)
           {
              num_set.insert(num);
           }

        }
        
        vector<int> res(num_set.begin(), num_set.end());
        return res;
    }
};