class Solution {
public:

    void trav(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        vis[i][j]=1;

        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for(int d=0;d<4;d++)
            {
                int nr = r+dx[d];
                int nc = c+dy[d];

                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='O' && !vis[nr][nc])
                {
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        // above below left and right

        // not boundary cell: will be surrounded by X -- change to X
        // set of X connected to boundary O cant be converted to X

        // dfs: 
            // start from boundary zeroes, and mark that IMPOSS to convert.

        vector<vector<int>> vis(board.size(), vector<int> (board[0].size(),0));
        // mark vis to boundary O cells. --> value distinct enough to eb able to identify sm1 visited this cell from boundary (when an inner cell is visited by boundary cell.)

        // trav first row & col, last row & col

        int n = board.size(), m = board[0].size();

        for(int i=0;i<m;i++)
        {
            if(!vis[0][i] && board[0][i]=='O') trav(0,i,vis,board);
            if(!vis[n-1][i] && board[n-1][i]=='O') trav(n-1,i,vis,board);
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O') trav(i,0,vis,board);
            if(!vis[i][m-1] && board[i][m-1]=='O') trav(i,m-1,vis,board);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]) board[i][j]='X';
            }
        }
    }
};