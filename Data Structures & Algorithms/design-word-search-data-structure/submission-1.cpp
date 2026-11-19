class WordDictionary {

struct Node {
    Node* letters [26] = {nullptr};
    bool isEnd = false;
};

private:
    Node* root;

    bool _search(string& word, int start, Node*& curr) {
        if(start == word.length()) return curr->isEnd;

        if(word[start] != '.') {
            int idx = word[start]-'a';
            if(curr->letters[idx] == nullptr) return false;

            return _search(word, start+1, curr->letters[idx]);
        }

        bool found = false;
        for(int l = 0; l < 26 && !found; l++) {
            if(curr->letters[l] != nullptr) {
                found = found || _search(word, start+1, curr->letters[l]);
            }
        }
        return found;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char ch : word) {
            int idx = ch-'a';
            if(curr->letters[idx] == nullptr) curr->letters[idx] = new Node();
            curr = curr->letters[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return _search(word, 0, root);
    }
};
