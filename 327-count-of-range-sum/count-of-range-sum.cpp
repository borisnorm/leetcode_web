/*
class Solution {
public:

struct SegTree {
    int n;
    vector<int> tree; // tree[node] = 该节点区间内元素数量

    SegTree(int n) : n(n), tree(4 * n, 0) {}

    // 在位置 pos 插入一个元素
    void update(int node, int l, int r, int pos) {
        if (l == r) { tree[node]++; return; }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(2*node, l, mid, pos);
        else            update(2*node+1, mid+1, r, pos);
        tree[node] = tree[2*node] + tree[2*node+1]; // 回传
    }

    // 查询 [ql, qr] 内元素数量
    int query(int node, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql <= l && r <= qr) return tree[node]; // 完全覆盖
        int mid = l + (r - l) / 2;
        int res = 0;
        if (ql <= mid) res += query(2*node, l, mid, ql, qr);
        if (qr > mid)  res += query(2*node+1, mid+1, r, ql, qr);
        return res;
    }

    void update(int pos) { update(1, 0, n-1, pos); }
    int query(int ql, int qr) { return query(1, 0, n-1, ql, qr); }
};

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();

    // 1. 构建前缀和
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + nums[i];

    // 2. 离散化：收集所有需要查询/插入的值
    vector<long long> vals(pre.begin(), pre.end());
    for (int j = 1; j <= n; j++) {
        vals.push_back(pre[j] - lower); // 查询上界
        vals.push_back(pre[j] - upper); // 查询下界
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end()); // 去重
    int m = vals.size();

    // 离散化映射：值 -> 索引
    auto getIdx = [&](long long v) {
        return (int)(lower_bound(vals.begin(), vals.end(), v) - vals.begin());
    };

    // 3. 扫描，线段树统计
    SegTree seg(m);
    int cnt = 0;

    for (int j = 0; j <= n; j++) {
        if (j > 0) {
            // 查询有多少 pre[i] 在 [pre[j]-upper, pre[j]-lower]
            int ql = getIdx(pre[j] - upper);
            int qr = getIdx(pre[j] - lower);
            cnt += seg.query(ql, qr); // pre[j]-lower 一定在 vals 里
        }
        // 插入 pre[j]
        seg.update(getIdx(pre[j]));
    }

    return cnt;
}
};

*/

class Solution {
public:
    // 主函数
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        int n = nums.size();                     // 数组长度
        
        vector<long long> prefix(n + 1, 0);      // 前缀和数组
        
        // 构造前缀和
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i]; // prefix[i] 表示前 i 个元素的和
        }
        
        // 使用归并排序统计
        return mergeSort(prefix, 0, n, lower, upper);
    }

private:
    
    // 归并排序函数
    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        
        // 递归终止
        if (left >= right) 
            return 0;
        
        int mid = left + (right - left) / 2;      // 中点
        
        int count = 0;
        
        // 递归左右两边
        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, right, lower, upper);
        
        // 统计跨区间的情况
        
        int j = mid + 1;
        int k = mid + 1;
        
        for (int i = left; i <= mid; i++) {
            
            // 找到第一个 >= prefix[i] + lower 的位置
            while (k <= right && prefix[k] - prefix[i] < lower)
                k++;
            
            // 找到第一个 > prefix[i] + upper 的位置
            while (j <= right && prefix[j] - prefix[i] <= upper)
                j++;
            
            // 中间区间数量
            count += (j - k);
        }
        
        // 合并排序
        vector<long long> temp;
        
        int p1 = left;
        int p2 = mid + 1;
        
        while (p1 <= mid && p2 <= right) {
            if (prefix[p1] <= prefix[p2])
                temp.push_back(prefix[p1++]);
            else
                temp.push_back(prefix[p2++]);
        }
        
        while (p1 <= mid)
            temp.push_back(prefix[p1++]);
        
        while (p2 <= right)
            temp.push_back(prefix[p2++]);
        
        // 拷回原数组
        for (int i = 0; i < temp.size(); i++) {
            prefix[left + i] = temp[i];
        }
        
        return count;
    }
};

/*
class Solution {
public:
    int lower_g;
    int upper_g;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lower_g = lower;
        upper_g = upper;

        int n = nums.size();
        vector<long long> pre(n+1, 0);
        for (int i = 0; i < n; i++)
          pre[i+1] = pre[i] + nums[i];
        
        return mergeSort(pre, 0, n+1);
    }

    int mergeSort(vector<long long>& pre, int l, int r)
    {
      if (r-l <= 1)
        return 0;
      
      int mid = l + (r-l)/2;
      int cnt = mergeSort(pre, l, mid) + mergeSort(pre, mid, r);

      int lo = mid;
      int hi = mid;

      for (int i = l; i < mid; i++)
      {
         while (lo < r && pre[lo] < (long long)pre[i] + lower_g)
           lo++;
        
         while (hi < r && pre[hi] <= (long long)pre[i] + upper_g)
           hi++;
        
         cnt += hi-lo;
      }

      vector<long long> tmp;
      int a = l;
      int b = mid;
      while (a < mid && b < r)
      {
        if (pre[a] <= pre[b])
          tmp.push_back(pre[a++]);
        else
          tmp.push_back(pre[b++]);
      }

      while(a < mid)
        tmp.push_back(pre[a++]);
    
      while (b < r)
        tmp.push_back(pre[b++]);
    
      for (int i = l; i < r; i++)
        pre[i] = tmp[i-l];  //写回
     
      return cnt;
    }
};

*/