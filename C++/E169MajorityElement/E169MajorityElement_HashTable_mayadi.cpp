//  Runtime:31ms
//  main.cpp
//  E169MajorityElement
//  
//  time:O(n)
//  space:O(n)
//
//  Created by MA YADI on 2018/4/7.
//  Copyright © 2018年 MA YADI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>hash;
        int i = 0;
        int n = nums.size();
        if(1==n)
            return nums[0];
        while(i<n){
            unordered_map<int,int>::const_iterator it=hash.find(nums[i]);
            if(it==hash.end()){
                hash.insert(make_pair(nums[i],1));
            }else{
                hash.at(nums[i]) = it->second+1;
                if(it->second > n/2)
                    return it->first;
            }
            i++;
        }
        return INT_MIN;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().majorityElement(nums);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

