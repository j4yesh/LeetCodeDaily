class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        n++;
        //Adjacency matrix
        vector<vector<pair<int,int>>>adj(n);
        //src dst cost
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<bool>visited(n);
        stack<int>q;
        q.push(1);
        visited[1]=true;
        vector<int>path;
        
        while(!q.empty()){
            int cur=q.top();
            q.pop();
            cout<<cur<<"->";
            for(auto it: adj[cur]){
                if(!visited[it.first]){
                    q.push(it.first);
                    visited[it.first]=true;
                }
                path.push_back(it.second);              
            }
        }
        cout<<"\n untilities: \n";
        for(auto it: path){
            cout<<it<<" ";
        }
        return *min_element(path.begin(),path.end());
    }
};
