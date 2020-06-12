class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int x1,y1,x2,y2;
        int count = 0;

        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j]==1){
                    x1 = i;
                    y1 = j;
                }else if(grid[i][j]==2){
                    x2 = i;
                    y2 = j;
                }else if(grid[i][j]==0)
                    count++;
            }
        }
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        dfs(grid,x1,y1,x2,y2,visited,res,count);
        return res;
    }
    void dfs(vector<vector<int>>& grid,int x1,int y1,int x2,int y2,vector<vector<int>>& visited,int& res,int count){
        if(x1<0||y1<0||x1>=grid.size()||y1>=grid[0].size()) return;
        if(visited[x1][y1]) return;
        if(grid[x1][y1]==-1) return;
        if(grid[x1][y1]==0) count--;

        if(x1==x2&&y1==y2&&count==0) {
            res += 1;
            return;
        }
        visited[x1][y1] = 1;
        dfs(grid,x1-1,y1,x2,y2,visited,res,count);
        dfs(grid,x1+1,y1,x2,y2,visited,res,count);
        dfs(grid,x1,y1-1,x2,y2,visited,res,count);
        dfs(grid,x1,y1+1,x2,y2,visited,res,count);
        visited[x1][y1] = 0;
    }
};