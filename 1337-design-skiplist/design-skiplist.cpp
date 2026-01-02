class Skiplist {
    struct Node{
        int val;
        vector<Node*> forward;
        Node(int _val, int level): val(_val), forward(level, nullptr){};
    };

    static const int MAX_LEVEL = 16;
    static constexpr double P = 0.5;

    Node* head;
    int level;

    int randomLevel()
    {
       int lvl = 1;
       while ((double)rand()/RAND_MAX < P && lvl < MAX_LEVEL)
         lvl++;

       return lvl;
    }
public:
    Skiplist() {
        level = 1;
        head = new Node(-1, MAX_LEVEL);
        srand(time(nullptr));
    }
    
    bool search(int target) {
        Node* cur = head;
        for (int i = level - 1; i >= 0; i--)
          while (cur->forward[i] && cur->forward[i]->val < target)
            cur = cur->forward[i];
        
        cur = cur->forward[0];
        return cur && cur->val == target;
    }
    
    void add(int num) {
        Node* cur = head;
        vector<Node*> update(MAX_LEVEL, nullptr);
        for (int i = level-1; i >= 0; i--)
        {
          while(cur->forward[i] && cur->forward[i]->val < num)
            cur = cur->forward[i];
          update[i] = cur;
        }

        int lvl = randomLevel();
        if (lvl > level)
        {
           for (int i = level; i < lvl; i++)
           {
               update[i] = head;
           }
           level = lvl;
        }

        Node* node = new Node(num, lvl);
        for (int i = 0; i < lvl; i++)
        {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }
    
    bool erase(int num) {
        Node* cur = head;
        vector<Node*> update(MAX_LEVEL, nullptr);

        for (int i = level -1; i >= 0; i--)
        {
            while (cur->forward[i] && cur->forward[i]->val < num)
               cur = cur->forward[i];
            
            update[i] = cur;
        }

        cur = cur->forward[0];

        if (!cur || cur->val != num)
          return false;
        
        for (int i = 0; i < level; i++)
        {
          if (update[i]->forward[i] != cur)
            break;
          update[i]->forward[i] = cur->forward[i];
        }

        while (level > 1 && head->forward[level - 1] == nullptr)
          level--;

        delete cur;
        
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */