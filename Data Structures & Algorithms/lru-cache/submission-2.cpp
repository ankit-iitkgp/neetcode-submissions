class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, Node*> ump;
    Node *head = nullptr;
    Node *tail = nullptr;

    int cap = 0;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(ump.find(key) == ump.end()) return -1;
        Node* node = ump[key];
        if(cap == 1 || node==tail) return node->value;
        if(node == head) {
            head = node->next;
        }
        else {
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;
        }
        node->prev = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
        return node->value;
    }
    
    void put(int key, int value) {
        Node *node = new Node(key, value);
        if(!head) {
            head = node;
            tail = node;
            ump[key] = node;
            return;
        }
        if(cap == 1) {
            head = node;
            tail = node;
            ump.clear();
            ump[key] = node;
            return;
        }
        if(ump.find(key) != ump.end()) {
            Node* curr = ump[key];
            if(curr == head) {
                head = curr->next;
                head->prev = nullptr;
                curr->next = nullptr;
            }
            else if(curr == tail) {
                tail = curr->prev;
                tail->next = nullptr;
                curr->prev = nullptr;
            }
            else {
                Node* prev = curr->prev;
                Node* next = curr->next;
                prev->next = next;
                next->prev = prev;
                curr->prev = nullptr;
                curr->next = nullptr;
            }
        }
        else if(ump.size() == cap) {
            Node* prev = head;
            int k = head->key;
            head = head->next;
            head->prev = nullptr;
            prev->next = nullptr;
            ump.erase(k);
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
        ump[key] = node;
        return;
    }
};
