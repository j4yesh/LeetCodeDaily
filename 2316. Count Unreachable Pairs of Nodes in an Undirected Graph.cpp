#define intl long long
class Solution {
private:
    int bfs(vector<bool>& visited, vector<vector<int>>& adj, int i) {
    queue<int> q;
    q.push(i);
    visited[i] = true;
    int cnt = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
                cnt++;
            }
        }
    } cout<<'\n';
    return cnt;
}
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long cnt=0;
        vector<vector<int>>adj(n);
        for(intl i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        vector<int>wrap;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int x=bfs(visited,adj,i);
                wrap.push_back(x);
            }
        }
        long long prod=0;
        long long sum=0;
        for(intl i=wrap.size()-1;i>=0;i--){
            prod+= wrap[i]*sum;
            sum+=wrap[i];
        }
        return prod;
    }
    };
