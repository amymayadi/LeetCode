//  Runtime: 6 ms
//  main.cpp
//  E027RemoveElement

//  time:O(n)
//  space:O(1)

//  Created by MA YADI on 2018/4/5.
//  Copyright © 2018年 MA YADI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
            return 0;
        
        int j = 1;
        if(val==nums[0])
            j=0;
        int i = 0;
        while(i<nums.size()){
            if(nums[i]!=val){
                if(i>=j)
                    nums[j++]=nums[i];
            }
            i++;
        }
        return j;
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

int stringToInteger(string input) {
    return stoi(input);
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

int main(int argc, const char * argv[]) {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int val = stringToInteger(line);
        
        int ret = Solution().removeElement(nums, val);
        
        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}

