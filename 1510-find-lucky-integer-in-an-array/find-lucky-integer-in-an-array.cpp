class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> num2freq;
        int maxLucky = INT_MIN;

        for (int& num: arr)
          num2freq[num]++;
        
        for (auto [num, freq]: num2freq)
        {    
           if (freq == num)
             maxLucky = max(maxLucky, num);
        }
        return maxLucky == INT_MIN ? -1 : maxLucky;
    }
};