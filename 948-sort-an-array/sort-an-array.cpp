class Solution {
public:

vector<int> sortArray(vector<int>& nums) {
     int n = nums.size();
     quickSort(nums, 0, n-1);
    return nums;
}

void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right)
      return;

    int pivotIdx =  left + rand() % (right-left + 1);
    int pivot = nums[pivotIdx];

    swap(nums[pivotIdx], nums[right]);

    int i = left;
    for (int j = left; j < right; j++)
    {
        if (nums[j] < pivot)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);

    quickSort(nums, left, i-1);
    quickSort(nums, i+1, right);
}
  /*
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
       if (left >= right)
         return;
        
        int mid = left + (right- left)/2;

        mergeSort(nums, left, mid);
        mergeSort(nums,  mid+1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int> & nums, int left, int mid, int right)
    {
        int n = right - left + 1;
        vector<int> temp(n);

        int i = left;
        int j = mid + 1;
        int k = 0; 

        while (i <= mid && j<= right)
        {
           if (nums[i] <= nums[j])
              temp[k++] = nums[i++];
            else
              temp[k++] = nums[j++];
        }

        while (i <= mid)
         temp[k++] = nums[i++];
        
        while (j <= right)
         temp[k++] = nums[j++];
        
        for (int i = 0; i < n; i++)
         nums[left+i] = temp[i];
    }

    */

};