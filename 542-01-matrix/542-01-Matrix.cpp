class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // bfs -- from all 1s you take 1 step -- reach possible 0 
        // bfs moves step by step.

        // we need single step together and not depth -- for minimum dist hence BFS

        vector<vector<int>> vis(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>> dis(mat.size(),vector<int>(mat[0].size(),0));

        queue<pair<pair<int,int>, int>> qp;
        int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    qp.push({{i,j}, 0});
                    vis[i][j]=1;
                }
                else vis[i][j]=0;
            }
        }

        int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
        while(!qp.empty())
        {
            int r = qp.front().first.first;
            int c = qp.front().first.second;
            int x = qp.front().second;
            qp.pop();

            dis[r][c]=x;

            for(int d=0;d<4;d++)
            {
                int nr = r+dx[d];
                int nc = c+dy[d];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    qp.push({{nr,nc},x+1});
                }
            }
        }
        return dis;
    }
};