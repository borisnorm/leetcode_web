class LRUCache {

    static class Node {
        int key;
        int val;
        Node prev;
        Node next;

        Node(int k, int v)
        {
            this.key = k;
            this.val = v;
        }
    }

    int cap;
    Node head;
    Node tail;

    HashMap<Integer, Node> key2node;
    public LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head.next = tail;
        tail.prev = head;
        
        key2node = new HashMap<>();
    }
    
    public int get(int key) {
        if (!key2node.containsKey(key))
          return -1;
        
        Node node = key2node.get(key);
        int val = node.val;

        updateLRUentry(node);

        return val;
    }
    
    public void put(int key, int value) {

        if (cap == 0)
          return;
          
        if (!key2node.containsKey(key) && key2node.size() == cap)
        {
            removeLRUentry();
        }

        if (key2node.containsKey(key))
        {
            Node node = key2node.get(key);
            node.val = value;

            updateLRUentry(node);
        }
        else
        {
            Node node = new Node(key, value);
            key2node.put(key, node);

            add2Head(node);
        }
    }


        void removeNode(Node node)
        {
            Node prev = node.prev;
            Node nxt  = node.next;

            prev.next = nxt;
            nxt.prev =  prev;

        }

        void add2Head(Node node)
        {
           Node nxt = head.next;

           head.next = node;
           node.prev = head;

           node.next = nxt;
           nxt.prev =  node;
        }

        void updateLRUentry(Node node)
        {
            removeNode(node);

            add2Head(node);
        }
        
        void removeLRUentry()
        {
            Node node = tail.prev;
            removeNode(node);
            key2node.remove(node.key);


        }
    
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */