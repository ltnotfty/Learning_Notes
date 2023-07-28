
#include <iostream>

class Solution {
public:

    bool isIsomorphic(string s, string t) {
        

        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;

        int sz = s.size();
        for (int i = 0;i < sz; ++i) {
            if (t2s.find(t[i]) == t2s.end() 
              && s2t.find(s[i]) == s2t.end()) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            
            if (s2t[s[i]] != t[i])
                return false;
        }


        return true;
    }
};

// hash
int main( int argc, char *argv[])
{



    return 0;
}
