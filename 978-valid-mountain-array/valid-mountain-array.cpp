class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        int i = 0; 

        while (i+1 < n && arr[i] < arr[i+1])
          i++;
        
        // i + 1 == n 的时候 arr[i] arr[i+1] 就不再执行了
        if (i == 0 || i + 1 == n)
          return false;
        
        while (i+1 < n && arr[i] > arr[i+1])
          i++;
        
        return (i+1) == n;
    }
};