class BrowserHistory {
public:
    vector<string>URL;
    int page=0;
    BrowserHistory(string homepage) {
        URL.push_back(homepage);
    }
    
    void visit(string url) {
        URL.erase(URL.begin()+page+1,URL.end());
        URL.push_back(url);
        page++;
    }
    
    string back(int steps) {
           page = max(0,page-steps);
        return URL[page];
    }
    
    string forward(int steps){
        for(auto it:URL){
            cout<<it<<" ";
        } cout<<endl;
        if(page+steps<URL.size()){
            page+=steps;
        }else{
            page=URL.size()-1;
        }
        return URL[page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
