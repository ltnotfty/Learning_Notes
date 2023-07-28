#include <iostream>




// sort + pointer

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort( citations.begin(), citations.end() );
        
        int sz = citations.size();
        int h = 1;
        int p = 0;
        int res = 0;

        while ( p < sz ) {

            while ( p < sz && citations[p] < h)
                ++p;
            if ( p != sz) {
                if ( sz - p >= h)
                    res = h;
                ++h;
            }
        }

        return res;
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {

        sort( citations.begin(), citations.end() );

        int sz = citations.size();
        int h = 0;
        int p = sz - 1;
        int res = 0;

        while ( p >= 0 && citations[p] > h) {
            --p;
            ++h;
        }

        return h;
    }
};

// sort + pointer









class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort( citations.begin(), citations.end() );
        
        int l = 1;
        int r = citations.size();
        int sz = citations.size();
        int  res = 0;
        // 1 1
        // 1 2 3 4
        while ( l <= r ) {
           
            int mid = l + ((r - l) >> 1);

            int pos = sz - mid;

            if ( citations[pos] > mid ) {
                res = max(res, mid);
                l = mid + 1;
            }
            else if ( citations[pos] < mid)
                r = mid - 1;
            else {
                res = max(res, mid);
                r = mid - 1;
            }
        }

        return res;
    }
};



// sort + binary search
int main(int argc, char *argv[])
{




    return 0;
}
