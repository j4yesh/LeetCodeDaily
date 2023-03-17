class Trie {
public:
    vector<string>rec;
    unordered_map<string,bool>mep;
    Trie(){
        
    }

    void insert(string word) {
        rec.push_back(word);
        mep[word]=true;
    }
    
    bool search(string word) {
        if(mep.find(word)!=mep.end()){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(string &it: rec){
            int cnt=0;
            for(int i=0;i<prefix.size();i++){
                if(prefix[i]==it[i]){
                    cnt++;
                }else{
                    break;
                }
            }
            if(cnt==prefix.size()){
                return true;
            }
        }
        return false;
    }
};
