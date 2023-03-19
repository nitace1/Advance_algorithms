class Trie {
public:
    struct node{
        node* arr[26];
        bool isEnded = false;
        void createNode(char ch, node* nxt){
              arr[ch - 'a'] = nxt;
        }
        node* newNode(char ch){
            return arr[ch - 'a'];
        }
        bool isNull(char ch){
            return (arr[ch - 'a'] == NULL);
        }
        void end(){
           isEnded = true;
        }
    };
    node* root;
    Trie() {
        root = new node();
    }
    
    void insert(string s) {
        node* temp = root;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(temp->isNull(s[i])) temp->createNode(s[i], new node());
            temp = temp->newNode(s[i]);
        }
        temp->end();
    }
    
    bool search(string s) {
        int n = s.size();
        node* temp = root;
        for(int i = 0;i<n;i++){
            if(temp->isNull(s[i]))return false;
            temp = temp->newNode(s[i]);
        }
        return temp->isEnded;
    }
    
    bool startsWith(string s) {
        int n = s.size();
        node* temp = root;
        for(int i = 0;i<n;i++){
            if(temp->isNull(s[i]))return false;
            temp = temp->newNode(s[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */