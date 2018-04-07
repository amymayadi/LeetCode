//  Runtime:4ms
//  main.cpp
//  E066PlusOne
//  
//  time:O(n)
//  space:O(1)
//    
//  Created by MA YADI on 2018/4/6.
//  Copyright © 2018年 MA YADI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 0){
            digits[0]=1;
            return digits;
        }
        
        int flag = 0, i = n-1;
        while(i<n && i>=0){
            // 末位为当前值加1
            if(i==n-1){
                digits[i] = digits[i]+1;
                if(digits[i] == 10){
                    if(n == 1)
                        digits.insert(digits.begin(),1);
                    else{
                        digits[i] = 0;
                        flag = 1;
                    }
                }
                else{
                    flag = 0;
                    return digits;
                }
            }
            else{
                digits[i]=digits[i]+flag;
                flag = 0;
                if(digits[i] == 10){
                    digits[i]=0;
                    if(i==0){
                        digits.insert(digits.begin(),1);
                    }else
                        flag = 1;
                }
            }
            i--;
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }
    
    if (length == 0) {
        return "[]";
    }
    
    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);
        
        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

