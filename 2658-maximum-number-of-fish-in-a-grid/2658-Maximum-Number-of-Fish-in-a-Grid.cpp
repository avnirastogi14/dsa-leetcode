class Solution {
public:

    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        int cnt = grid[i][j]; // fish count;

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int d=0;d<4;d++)
            {
                int nr = r+dx[d];
                int nc = c+dy[d];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]>0)
                {
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                    cnt+=grid[nr][nc];
                }
            }
        }
        return cnt;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    int curr = bfs(i,j,grid);
                    ans = max(curr,ans);
                }
            }
        }
        return ans;
    }
};