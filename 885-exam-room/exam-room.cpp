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

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */