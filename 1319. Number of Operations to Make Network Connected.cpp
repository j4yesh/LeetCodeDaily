class Solution {
private:
    void nfs(vector<bool>&visited,vector<vector<int>>&adj,int i){
       queue<int>q;
    q.push(i); visited[i]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto it: adj[cur]){
            if(!visited[it]){
                visited[it]=true;
                q.push(it);
            }
        }
    }
        
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        int m=connections.size();
        int p=INT_MIN;
        int edges=0;
        for(int i=0;i<m;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            p=max(p,connections[i][0]); 
            p=max(p,connections[i][1]);
            edges++;
        }
        vector<bool>visited(n);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                nfs(visited,adj,i);
                cout<<"eye: "<<i<<endl;
                comp++;
            }
        }
        int red=edges-((n-1)-(comp-1));
        cout<<"redun: "<<red<<endl;
        cout<<"comp: "<<comp<<endl;
        if(edges<n-1){
            return -1;
        }    
        if(red>=comp-1){
            return comp-1;
        }  
        return -1;
    }   
};
