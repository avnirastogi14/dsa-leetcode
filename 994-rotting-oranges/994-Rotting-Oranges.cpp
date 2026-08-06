class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int ok = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2) q.push({i,j}); //bad
                else if(grid[i][j]==1) ok++;
            }
        }

        if(ok==0) return 0;

        int time = 0;

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!q.empty())
        {
            int s = q.size(); //multi source bfs
            bool rot = false;

            while(s--)
            {
                pair<int,int> p = q.front();
                q.pop();
                
                for(int d=0;d<4;d++)
                {
                    int nr = dx[d]+p.first;
                    int nc = dy[d]+p.second;

                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1) grid[nr][nc]=2; //mark rot;
                    ok--; // reduce ok oranges
                    flag = true;

                    q.push({nr,nc});
                }
                if(flag) time++;
            }
        }
        if(fresh>0) return -1; //all cant rot

        return time;
    }
};