class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp = {
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
        };

        int n = num.size();
        int l = 0; 
        int r = n - 1;
        while (l <= r)
        {
           if (!mp.count(num[l]) || mp[num[l]] != num[r])
             return false;
            
            l++;
            r--;
        }

        return true;
    }
};