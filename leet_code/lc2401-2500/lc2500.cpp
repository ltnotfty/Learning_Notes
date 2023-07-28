#include <iostream>





class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {

        int rows = grid.size();
        if (!rows)
            return 0;
        int cols = grid[0].size();

        for ( int i = 0; i < rows; ++i) {
            sort(grid[i].begin(), grid[i].end() );
        }

        int res = 0;
        for ( int i = 0; i < cols; ++i ) {
            int mx = grid[0][i];
            for ( int j = 1; j < rows; ++j) {
                if ( mx < grid[j][i])
                    mx = grid[j][i];
            }
            // printf("mx: %d\n", mx);
            res += mx;
        }


        return res;
    }
};


// sort 


int main( int argc, char *argv[]) {




    return 0;
}
