class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
     int n = arr.size();
     int l = 0;
     int r = n-1;

     while (l < r)
     {
        int mid = l + (r -l)/2;

        // monolithic increase on this part 
        // n-1 < n
        // mid =  n - 1 + n-(n-1)/2 = n - 1 + 1/2 = n + 1/2 
        if (arr[mid] < arr[mid+1])
        {
           l = mid + 1;
        }
        else
        { 
           r = mid;
        }

     }

     return l;
  }
    /*
    int peakIndexInMountainArray(vector<int>& arr) {
        //monolithc stack 

        int n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
           while (!st.empty() && arr[i] > arr[st.top()])
             st.pop();

           st.push(i);
        }

        int peakIdx = 0;
        while (!st.empty())
        {
           peakIdx = st.top();
           st.pop();
        }

        return peakIdx;
    }
    */
};