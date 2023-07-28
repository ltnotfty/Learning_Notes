#include <iostream>



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res;
        for ( int i = 0;i < n; ++i) {
            vector tmp(n,0);
            res.push_back(tmp);
        }


        int lb = 0;
        int rb = n - 1;
        int ub = 0;
        int db = n - 1;
        int val = 1;

        while ( 1 ) {

            for ( int i = lb; i <= rb; ++i)
                res[ub][i] = val++;
            
            if (++ub > db)
                break;
            
            for ( int i = ub; i <= db; ++i)
                res[i][rb] = val++;
            
            if ( --rb < lb)
                break;
            
            for ( int i = rb; i >= lb; --i)
                res[db][i] = val++;
            
            if ( --db < ub)
                break;
            
            for ( int i = db; i >= ub; --i)
                res[i][lb] = val++;
            
            if ( ++lb > rb)
                break;
        } 

        return res;
    }
};


// simulation + cnt  








int main( int argc, char *argv[])
{





    return 0;
}
