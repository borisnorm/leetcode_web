class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // first two

        int n = letters.size();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
           int mid = l + (r-l)/2;
           if (letters[mid] > target)
           {
              r = mid;
           }
           else
           {
              l = mid + 1;
           }
        }

        if (letters[l] <= target)
          return letters[0];
        
        return letters[l];
    }
};