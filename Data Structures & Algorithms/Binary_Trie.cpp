struct Trie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() : cnt(0) {
            memset(child, 0, sizeof(child));
        }
    };
    Node *root;
    Trie() {
        root = new Node();
    }
    void add(int x) {
        Node *node = root;
        node->cnt++;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->child[bit] == NULL) {
                node->child[bit] = new Node();
            }
            node = node->child[bit];
            node->cnt++;
        }
    }

    int get(int x) {
        Node *node = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node->child[!bit] != NULL && node->child[!bit]->cnt > 0) {
                res |= (1 << i);
                node = node->child[!bit];
            } else if (node->child[bit] != NULL && node->child[bit]->cnt > 0) {
                node = node->child[bit];
            } else {
                assert(0);
            }
        }
        return res;
    }
    void remove(int x) {
        Node *node = root;
        node->cnt--;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            node = node->child[bit];
            node->cnt--;
        }
    }
};
