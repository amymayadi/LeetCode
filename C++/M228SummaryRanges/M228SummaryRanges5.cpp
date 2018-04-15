//  main.cpp
//  M228SummaryRanges
//
//  Created by MA YADI on 2018/4/13.
//  Copyright © 2018年 MA YADI. All rights reserved.
/**
 * Runtinme: 4ms (SLOW alg)
 * time: O(n)
 * space: O(n)
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0)
            return res;
        
        if(n == 1) {
            string str = to_string(nums[0]);
            res.push_back(str);
            return res;
        }
        
        int i = 0;
        int lt = nums[0];
        int rt = nums[0];
        bool bsame = true; // last compare whether the two number is same.
        while(i<=n-1){
            string strlt = to_string(lt);
            string strrt = to_string(rt);
            if(i == n-1) {
                if(!bsame)
                    res.push_back(to_string(nums[n - 1]));
                else
                    res.push_back(strlt + "->" + strrt);
                return res;
            }
            else if(nums[i+1]>nums[i]+1) {
                bsame = false;
                if(rt == lt) {
                    res.push_back(strlt);
                }else {
                    res.push_back(strlt + "->" + strrt);
                }
                rt = lt = nums[++i];
            }
            else{
                bsame = true;
                rt = nums[++i];
            }
        }
        return res;
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

string stringVectorToString(vector<string> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }
    
    if (length == 0) {
        return "[]";
    }
    
    string result;
    for(int index = 0; index < length; index++) {
        string str = list[index];
        result += str + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        vector<string> ret = Solution().summaryRanges(nums);
        string result = stringVectorToString(ret);
        cout << result;
        for (const string str : ret) {
            cout << str << ",";
        }
    }
    return 0;
}

