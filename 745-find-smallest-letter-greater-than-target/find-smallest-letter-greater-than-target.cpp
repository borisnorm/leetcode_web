class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n = letters.size();
        int l = 0;
        int r = n - 1;

        while (l < r)
        {
           int mid = l + (r-l)/2;
           // upper bound  > target, 返回第一个大于 target 的 l
           if (letters[mid] > target)
           {
              r = mid;
           }
           else
           {
              l = mid + 1;
           }
        }
        
        // 没有找到结果, 根据题意返回 第一个字符
        if (letters[l] <= target)
          return letters[0];
        
        return letters[l];
    }
};

/*
char nextGreatestLetter(vector<char>& letters, char target)
{
    int n = (int)letters.size();
    int left = 0;
    int right = n;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (letters[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left == n ? letters[0] : letters[left];
}

*/