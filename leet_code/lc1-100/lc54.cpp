#include <iostream>

class Solution {
public:
    vector<int> getEndPos(int x, int y) {
        if (x == 1)
            return {0, max(0,y - 1)};
        if (y == 1)
            return {max(0,x - 1), 0};
        if ( x == 2 || y == 2)
            return { 1, 0};

        
        int retx = 0, rety = 0;
        while ( x > 2 && y > 2) {
            retx++;
            rety++;

            x -= 2;
            y -= 2;
        }
        vector<int> tmp = getEndPos(x,y);

        retx += tmp[0];
        rety += tmp[1];

        return {retx, rety};
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;

        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<int> cur{0,0};
        vector<int> ePos = getEndPos( rows, cols );


         std::cout << ePos[0] << ":" << ePos[1] << std::endl;
        int ctr_bit = 0;
        int lb = -1;
        int rb = cols;
        int ub = 0;
        int bb = rows;

        while (1) {
            
            res.push_back(matrix[cur[0]][cur[1]]);
           // std::cout << cur[1] << ":" << cur[0] << std::endl;
            if (cur == ePos) {
                
                break;
            }
            // printf("%d\n", ctr_bit);
            if ( ((ctr_bit & 1) == 0) && (cur[1] + 1 < rb ) ) {
                //printf("here");
                cur[1] = cur[1] + 1;
                continue;
            }
            ctr_bit |= 1;
            
            if ( (ctr_bit & 2) == 0 && 
                 (cur[0] + 1 < bb) ) {
                cur[0] = cur[0] + 1;
                continue;
            }
            ctr_bit |= 2;

            if ( (ctr_bit & 4) == 0 && ((cur[1] - 1) > lb) ){
                cur[1] = cur[1] - 1;
                printf("%d\n" ,cur[0]);
                continue;
            }
            ctr_bit |= 4;
            if ( (ctr_bit & 8) == 0 && cur[0] - 1 > ub) {
                cur[0] = cur[0] - 1;
                continue;
            }
            ctr_bit |= 8;

            ++lb;
            --rb;
            ++ub;
            --bb;
            ctr_bit &= 0;
            cur[1]++;

        }

        return res;
    }
};class Solution {
public:
    vector<int> getEndPos(int x, int y) {
        if (x == 1)
            return {0, max(0,y - 1)};
        if (y == 1)
            return {max(0,x - 1), 0};
        if ( x == 2 || y == 2)
            return { 1, 0};

        
        int retx = 0, rety = 0;
        while ( x > 2 && y > 2) {
            retx++;
            rety++;

            x -= 2;
            y -= 2;
        }
        vector<int> tmp = getEndPos(x,y);

        retx += tmp[0];
        rety += tmp[1];

        return {retx, rety};
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;

        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<int> cur{0,0};
        vector<int> ePos = getEndPos( rows, cols );


         std::cout << ePos[0] << ":" << ePos[1] << std::endl;
        int ctr_bit = 0;
        int lb = -1;
        int rb = cols;
        int ub = 0;
        int bb = rows;

        while (1) {
            
            res.push_back(matrix[cur[0]][cur[1]]);
           // std::cout << cur[1] << ":" << cur[0] << std::endl;
            if (cur == ePos) {
                
                break;
            }
            // printf("%d\n", ctr_bit);
            if ( ((ctr_bit & 1) == 0) && (cur[1] + 1 < rb ) ) {
                //printf("here");
                cur[1] = cur[1] + 1;
                continue;
            }
            ctr_bit |= 1;
            
            if ( (ctr_bit & 2) == 0 && 
                 (cur[0] + 1 < bb) ) {
                cur[0] = cur[0] + 1;
                continue;
            }
            ctr_bit |= 2;

            if ( (ctr_bit & 4) == 0 && ((cur[1] - 1) > lb) ){
                cur[1] = cur[1] - 1;
                printf("%d\n" ,cur[0]);
                continue;
            }
            ctr_bit |= 4;
            if ( (ctr_bit & 8) == 0 && cur[0] - 1 > ub) {
                cur[0] = cur[0] - 1;
                continue;
            }
            ctr_bit |= 8;

            ++lb;
            --rb;
            ++ub;
            --bb;
            ctr_bit &= 0;
            cur[1]++;

        }

        return res;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;

        int lb = 0;
        int rb = matrix[0].size() - 1;
        int ub = 0;
        int db = matrix.size()  -1;
        while (1) {

            for ( int i = lb; i <= rb; ++i) {
                res.push_back(matrix[ub][i] );
            }
            if ( ++ub > db)
                break;
            for ( int i = ub; i <= db;++i) {
                res.push_back(matrix[i][rb]);
            }
            if (--rb < lb) {
                break;
            }

            for ( int i = rb; i >= lb; --i) {
                res.push_back(matrix[db][i]);
            }
            if ( --db < ub)
                break;
            for ( int i = db; i >= ub; --i) {
                res.push_back(matrix[i][lb]);
            }
            if ( ++lb > rb)
                break;
        }


        return res;
    }
};

















int main( int argc, char *argv[]) {



    return 0;
}
