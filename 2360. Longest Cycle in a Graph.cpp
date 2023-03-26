class Solution {
private:
    void topo(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st,int i){
        visited[i]=true;
        for(auto it: adj[i]){
            if(!visited[it]){
                topo(adj,visited,st,it);
            }
        }
        cout<<i<<" "; // correct
        st.push(i);
    }
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int it,vector<int>&temp){
        visited[it]=true;
        temp.push_back(it);
        for(auto ut: adj[it]){
            if(!visited[ut]){
                dfs(adj,visited,ut,temp);
            }
        }
    }
    int kosaraju(vector<vector<int>>&adj,int n){
        stack<int>st;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topo(adj,visited,st,i);
            }
        }
        //topological sort is ready 
        vector<vector<int>>revadj(adj.size());
        for(int i=0;i<n;i++){
            visited[i]=false;
            for(auto it: adj[i]){
                revadj[it].push_back(i);
            }
        }
        int ans=0;
        while(st.size()){
            int cur=st.top();
            st.pop();
                if(!visited[cur]){
                    vector<int>temp;
                    dfs(revadj,visited,cur,temp);
                    ans=(ans>temp.size())?ans:(int)temp.size();
                }
        }
        return ans;
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<vector<int>>adj(edges.size());
        for(int i=0;i<edges.size();i++){
            if(edges[i]>=0)
                adj[i].push_back(edges[i]);
        }
        int ans=kosaraju(adj,edges.size());
        if(ans>1){
            return ans;
        }
        return -1;
    }
};
