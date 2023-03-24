#define outgoing true
#define incoming false
class Solution {
private:
    int cnt=0;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<vector<pair<int,bool>>>adj(m+1);
        for(int i=0;i<m;i++){
            adj[connections[i][0]].push_back({connections[i][1],outgoing});
            adj[connections[i][1]].push_back({connections[i][0],incoming});
        }
        vector<bool>visited(n,false);
        int cnt=0;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int cur=q.front();
            q.pop(); //prev ko chodke dusre ko denote krna
            for(auto it: adj[cur]){
                if(!visited[it.first]){
                    if(it.second==outgoing){
                        cnt++;
                    }
                    visited[it.first]=true;
                    q.push(it.first);
                }
            }
        } 

        return cnt;          
    }
};
