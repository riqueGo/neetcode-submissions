class Node {
public:
    Node* letters [26] = {nullptr};
    bool isEnd = false;
};

class PrefixTree {
private:
    Node* root;

    Node* _search(string word) {
        Node* curr = root;
        for(char ch : word) {
            int idx = ch-'a';
            if(curr->letters[idx] == nullptr) return nullptr;
            curr = curr->letters[idx];
        }
        return curr;
    }

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char ch : word) {
            int idx = ch-'a';
            if(curr->letters[idx] == nullptr) {
                curr->letters[idx] = new Node();
            }
            curr = curr->letters[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = _search(word);
        return curr != nullptr && curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = _search(prefix);
        return curr != nullptr;
    }
};
