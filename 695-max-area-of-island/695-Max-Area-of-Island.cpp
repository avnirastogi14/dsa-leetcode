class Solution {
public:

    int bfs(int i, int j, vector<vector<int>> grid)
    {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>> q;

        q.push({i,j});
        vis[i][j]=true;

        int cnt = 1;

        int dx[]={-1,1,0,0}; // -x +x 0 0
        int dy[]={0,0,-1,1};

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            for(int d=0;d<4;d++)
            {
                int nr = dx[d]+curr.first;
                int nc = dy[d]+curr.second;

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int ans = INT_MIN;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    int currSize = bfs(i,j,grid);
                    ans = max(ans,currSize);
                }
            }
        }
        return (ans==INT_MIN)?0:ans;
    }
};