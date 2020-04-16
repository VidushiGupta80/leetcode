//Maximum 69 Number -> 04/16/2020 19:18
class Solution {
public:
    int maximum69Number (int num) {
      
        /*string result;          
        ostringstream convert; 
        convert << num;  
        result = convert.str();
        int len = result.size();
        for(int i = 0; i < len; i++)
        {
            if(*(result + i) == "6")
            {
                *(result + i) = "9";
                break;
            }
        }
        int finalNum;
        istringstream convert(result); 
        if ( !(convert >> finalNum) ) 
            finalNum = 0;
        return finalNum; */
        
        
        int count = 1;
        int number = num;
        while(number / 10 > 0)
        {
            number /= 10;
            count ++;
        }
        number = num;
        int temp = 0;
        for(int i = count - 1; i >= 0; i--)
        {
            if(number < 9 * powl(10, i))
            {
                number -= 6 * powl(10, i);
                number += 9 * powl(10, i);
                break;
            }
            else
            {
                number -= 9 * powl(10, i);
                temp += 9 * powl(10, i);
            }
        }
        temp += number;
        return temp;
            
    }
};
