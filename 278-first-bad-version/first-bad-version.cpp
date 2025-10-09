// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //[bad, n] = true;
        //isBadVersion

        int left = 1;
        int right = n;

        bool res = false;

        while (left < right)
        {
          int mid = left + (right-left)/2;
          if(isBadVersion(mid))
            right = mid;
           else
            left = mid+1;
        } 

        return left;
    }
};