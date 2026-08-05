class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int X)
    {
        int l = 0, h = mat.size()*mat[0].size()-1;

        while(l<=h)
        {
            int m = (h+l)/2;
            int r = m/(int)mat[0].size(), c = m%((int)mat[0].size());
            if(mat[r][c]==X) return true;
            else if(X<mat[r][c]) h=m-1;
            else l=m+1;
        }
        return false;
    }
};