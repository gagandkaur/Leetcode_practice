class Solution {
public:
    string convertToBase7(int num) {
      if ( num == 0 ) return "0";
      
      bool isMin = num <0; 
      num = abs (num);
      string  out ="";

      while ( num > 0){
        int r = num%7;
        out += to_string(r);
        num/=7;}
        reverse (out.begin(), out.end());
        if (isMin) out ="-" + out;
        
    return out;
      }  
    
};   
    