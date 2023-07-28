#include <iostream>


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int rcv_tm = 0;
        int sz = timeSeries.size();
        int ret = 0;

        for ( int i = 0; i < sz; ++i) {
            
            int add_tm = duration;
            if ( rcv_tm > timeSeries[i])
                add_tm -= rcv_tm - timeSeries[i];
            
            ret += add_tm;
            rcv_tm = duration + timeSeries[i];
        }

        return ret;
    }
};

// arr

int main( int argc, char *argv[])
{







    return 0;
}
