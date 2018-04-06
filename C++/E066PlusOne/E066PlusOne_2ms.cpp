//  Runtime:2ms
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1;
        int flag=0;
        for(i;i>=0;i--)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
                flag=1;
                //digits.insert(digits.begin()+i,1);
                //break;
            }
            else
            {   
                
                digits[i]=digits[i]+1; break;
        
             }
        }
        //if(flag)    digits.insert(digits.begin()+i,1);
         if (digits.front()==0){  
            digits.insert(digits.begin(),1);  
        } 
        return digits;
    }
};
