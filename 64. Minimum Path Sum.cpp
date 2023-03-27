class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> met(m, vector<int>(n)); //n size ka aur sbko sec assign hai
        met[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            met[0][i]=met[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++){
            met[i][0]=met[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                met[i][j]=min(met[i-1][j],met[i][j-1])+grid[i][j];
                cout<<met[i][j]<<' ';
            }
            cout<<endl;
        }
        return met[m-1][n-1];
    }
};
