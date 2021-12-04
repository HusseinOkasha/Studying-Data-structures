class TrieNode{
    public:
    char val;
    unordered_map<char, TrieNode*>children;
    bool is_end;
    
    TrieNode(){
        
        is_end = false;
    }
    TrieNode(char val){
        this->val = val;
        is_end = false;
    }
    void setEnd(){
        is_end = true;
    }
    
};
class Trie {
public:
    TrieNode * root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* head = root;
        for(int i=0; i< word.size() ;i++){
            if(!head->children[word[i]]){
                head->children[word[i]] = new TrieNode(word[i]);
            }
            head = head->children[word[i]];
        }
        head->setEnd();
        
    }
    bool search(string word) {
        TrieNode* head = root;
        for(int i=0; i< word.size() ;i++){
            if(!head->children[word[i]]){
                return false;
            }
            else{
                head = head->children[word[i]];    
            }
        }
        return head->is_end;
    }
    bool startsWith(string prefix) {
        TrieNode* head = root;
        for(int i=0; i< prefix.size() ;i++){
            if(!head->children[prefix[i]]){
                return false;
            }
            else{
                head = head->children[prefix[i]];    
            }
        }
        return true;
    }
};

