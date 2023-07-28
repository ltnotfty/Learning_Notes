#include <iostream>











class Solution {
public:
    bool dfs(int i, int j, vector<vector<char> >& grid, vector<vector<char>> & isVisit) {
        if ( 0 != isVisit[i][j])
            return false;
        isVisit[i][j] = 1;

        if ( grid[i][j] == '0')
            return false;

        int rows = grid.size();
        int cols = grid[0].size();
        
        if (i - 1 > -1)
            dfs( i - 1, j, grid, isVisit);
        if (i + 1 < rows)
            dfs( i + 1, j , grid, isVisit);
        if ( j - 1 > -1)
            dfs( i, j - 1, grid, isVisit);
        if ( j + 1 < cols)
            dfs( i, j + 1, grid, isVisit);

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int cols = 0;
        int rows = 0;

        rows = grid.size();
        cols = grid[0].size();

        vector<vector<char> > isVisit;
        for ( int i = 0;i < rows; i++) { 
            vector<char> tmp;
            for (int j = 0; j < cols; j++) {
                tmp.push_back(0);
            }
            isVisit.push_back(tmp);
        }

        int res = 0;

        for ( int i = 0; i < rows; ++i) {
            for ( int j = 0; j < cols; ++j) {
                if ( dfs(i,j, grid, isVisit))
                    res++;
            }
        }
        
        return res;
    }
};




int main(int argc, char *argv[])
{



    return 0;
}
