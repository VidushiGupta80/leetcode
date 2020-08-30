//Ugly Number -> 08/30/2020 22:04
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return 0;
        if(num==1) return 1;
        while(num!=1){
           
           if(num%2==0){
               num/=2;
               continue;
           }else if(num%3==0){
               num/=3;
               continue;
           }else if(num%5==0){
               num/=5;
               continue;
           }
           else{
               return 0;
           }
       }
        return 1;
    }
};
