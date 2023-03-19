class TrieNode{
public:
    bool iscomplet;
    TrieNode* child[26];
    TrieNode() {
        iscomplet = false; 
        memset(child, 0, sizeof(child));
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            int ch=word[i]-'a';// D ref corresponding to index 
            if(temp->child[ch]==NULL){
                temp->child[ch]=new TrieNode();
                temp=temp->child[ch];
            }else{
                temp=temp->child[ch];
            }
        }
        temp->iscomplet=true;
    }
    
    bool search(string word) {
        return searchify(word,root);
    }
    bool searchify(string word,TrieNode *root){
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                for(auto ch: root->child){
                    if(ch && searchify(word.substr(i+1),ch) ){
                        return true;
                    }
                }    
                return false;
            }
            int ch=word[i]-'a';
            if(root->child[ch]==NULL){
                return false;
            }
            root=root->child[ch];
        }
        return root->iscomplet;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
