#include <iostream>


class Solution {
public:

    string getBelowTen(int num) {
        std::string ret;
        if (num == 9)
            ret = "IX";
        else if (num == 4)
            ret = "IV";
        else if (num){
            if(num >= 5) {
                ret += 'V';
                num -= 5;
            }
            while (num > 0) {
                num--;
                ret += 'I';
            }
        }   
        else
            return "";
        return ret;
    }
    string getBelowThInt(int num) {
        int h_int = num%1000 / 100;
        if ( h_int == 4)
            return "CD";
        else if ( h_int == 9)
            return "CM";
        else if ( h_int) {
            std::string ret;
            if (h_int >= 5){
                ret += "D";
                h_int -= 5;
            }
            
            while (h_int > 0){
                ret += 'C';
                h_int--;
            }
            return ret;
        }
        else{
            return "";
        }
    }
    string getBelowHunInt(int num) {
        int h_int = num %100 / 10;
        if ( h_int == 4)
            return "XL";
        else if ( h_int == 9)
            return "XC";
        else if ( h_int ) {
            std::string ret;
            if (h_int >= 5){
                ret += "L";
                h_int -= 5;
            }
            
            while ( h_int > 0) {
                ret += 'X';
                h_int--;
            }
            return ret;
        }
        else{
            return "";
        }
    }

    string intToRoman(int num) {
        

        std::string res;
       
       if (num >= 1000) {
           int t_num = num / 1000;
           while (t_num > 0){
               res += 'M';
                t_num--;
           }
           num %= 1000; 
       }
       std::cout << res << std::endl;
       res += getBelowThInt(num);
       num %= 100;
       res += getBelowHunInt(num);
       num %= 10;
       res += getBelowTen(num);

        
        return res;
    }
};



 static const std::pair<int,std::string> sym_val[] = {
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };
class Solution {

   
public:



    string intToRoman(int num) {
        
        string roman;
        for (const auto &[value,symbol]: sym_val ) {

            while( num >= value) {
                num -= value;
                roman += symbol;
            }
            if ( num == 0)
                break;
        }

        return roman;
    }
};

// table + gready 

int main( int argc, char *argv[])
{




    return 0;
}
