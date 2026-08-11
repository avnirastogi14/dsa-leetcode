class Solution {
public:

    void bfs(int ci, int cj, vector<vector<bool>> &vis, vector<vector<char>> g)
    {
        int tr = g.size();
        int tc = g[0].size();

        queue<pair<int,int>> q;
        q.push({ci,cj});
        vis[ci][cj]=true;

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        while(!q.empty())
        {
            pair<int,int> p=q.front(); //curr node
            q.pop();

            int i=p.first; int j=p.second;

            for(int d=0;d<4;d++)
            {
                int nr=i+dx[d];
                int nc=j+dy[d];

                if(nr>=0 && nc>=0 && nr<tr && nc<tc && g[nr][nc]=='1' && !vis[nr][nc])
                {
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& g) {
        int tr = g.size();
        int tc = g[0].size();

        vector<vector<bool>> vis(tr,vector<bool> (tc,false));

        int ans=0;

        for(int i=0;i<tr;i++)
        {
            for(int j=0;j<tc;j++)
            {
                if(g[i][j]=='1')
                {
                    if(vis[i][j]==false)
                    {
                        ans++;
                        bfs(i,j,vis,g);
                    }
                }
            }
        }

        return ans;
    }
};