class ExamRoom
{
public:
   int n;
   set<int> seats;

   struct cmp
   {
      int n;
      cmp(int n): n(n){}

      //pos, dist
      pair<int, int> best(int l, int r) const
      {
          if (l == -1)
            return {0, r};
          if (r == n)
            return  {n-1, n-1-l};
          
          return {l + (r-l)/2, (r-l)/2};
      }

      bool operator()(pair<int, int> a, pair<int, int> b) const
      {
         auto [pos_a, dist_a] = best(a.first, a.second);
         auto [pos_b, dist_b] = best(b.first, b.second);
         if (dist_a != dist_b)
           return dist_a > dist_b;  // dist 大的拍在前面
         
         return pos_a < pos_b;
      }
   };

   set<pair<int, int>, cmp> gaps;

   ExamRoom(int n): n(n), gaps(cmp(n))
   {
      seats.insert(-1);
      seats.insert(n);
      gaps.insert({-1, n});
   }

   int seat()
   {
      auto [l, r] = *gaps.begin();
      auto [pos, dist] = gaps.key_comp().best(l, r);

      gaps.erase(gaps.begin());
      gaps.insert({l, pos});
      gaps.insert({pos, r});
      seats.insert(pos);

      return pos;
   }

   void leave(int p)
   {
      auto it = seats.find(p);
      int l = *prev(it);
      int r = *next(it);

      gaps.erase({l, p});
      gaps.erase({p, r});

      gaps.insert({l, r});

      seats.erase(it);
   }
};
/*
class ExamRoom
{
public:
    int n;
    set<int> seats; // 已占座位（含哨兵 -1 和 n）

    // gap 存 (-dist, left, right)
    // -dist：dist 越大越靠前（set 默认升序，取负变成降序）
    // left 越小越靠前（相同 dist 取编号小的）
    set<tuple<int,int,int>> gaps;

    // {-11, -1, 2, 3, 4, 5}

    // -{-11, -1, 2, 3, 4, 5}
    // {11, 1, 2, -2, -3, -4, -5}

    // 计算间隔 (l, r) 的最优座位和距离
    // 返回的是{pos, dist}
    // {最优作为 pos, 该间隔的最优距离 dist}
    pair<int,int> best(int l, int r)
    {
        if (l == -1)
            return {0, r};          // 左边界
        if (r == n)
            return {n-1, n-1-l};    // 右边界

        return {l+(r-l)/2, (r-l)/2}; // 中间取中点
    }

    void addGap(int l, int r)
    {
        auto [pos, dist] = best(l, r);
        gaps.insert({-dist, l, r}); // dist 取负，set 升序即最大 dist 在前
    }

    void rmGap(int l, int r)
    {
        auto [pos, dist] = best(l, r);
        gaps.erase({-dist, l, r});
    }

    ExamRoom(int n) : n(n)
    {
        seats.insert(-1);
        seats.insert(n);
        addGap(-1, n); // 初始只有一个间隔
    }

    int seat()
    {
        auto [neg_dist, l, r] = *gaps.begin(); // 取最优间隔
        auto [pos, dist] = best(l, r);
        // pos 坐进间隔 (l, r) 后，原来的一个大间隔被分成两个小间隔：
        rmGap(l, r);          // 删掉旧间隔
        addGap(l, pos);       // 加入左半段
        addGap(pos, r);       // 加入右半段
        seats.insert(pos);

        return pos;
    }

    void leave(int p)
    {
        auto it = seats.find(p);

        // 找 p 的左右邻居
        auto r_it = next(it);
        auto l_it = prev(it);
        int l = *l_it;
        int r = *r_it;

        rmGap(l, p); // 删掉 p 左侧间隔
        rmGap(p, r); // 删掉 p 右侧间隔
        addGap(l, r); // 合并成一个新间隔

        seats.erase(it);
    }
};

*/

/*
class ExamRoom {
public:
    int n;
    set<int> seat_set;
    ExamRoom(int n) {
      this->n = n;
      seat_set.insert(-1);
      seat_set.insert(n);
    }
    
    int seat() {
      int best = 0;
      int bestDist = 0;
      auto it = seat_set.begin();
      int l = *it++; //  l 是 -1

      for (; it != seat_set.end(); it++)
      {
        int r = *it;
        int pos = 0;
        int dist = 0;
        if (l == -1)
        {
          pos = 0;
          dist = r;
        }
        else if (r == n)
        {
          pos = n - 1;
          dist = n - 1 - l; // dist 是距离, 不包括 l 那个位置
        }
        else
        {
          pos = l + (r-l)/2;
          dist = (r-l)/2;
        }

        if (dist > bestDist || (dist == bestDist && pos < best))
        {
            bestDist = dist;
            best = pos;
        }

        l = r;
      }

      seat_set.insert(best);
      return best;
    }
    
    void leave(int p) {
       seat_set.erase(p);
    }
};
*/

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */