//
//  main.cpp
//  E006ZigZagConversion
//
//  Created by MA YADI on 2018/4/19.
//  Copyright © 2018年 MA YADI. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

static const void* ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string convert(string s, int numRows) {
        int nCount = s.length();
        if (numRows >= nCount || numRows <= 1)
            return s;
        int step = 1;
        int r = 0;
        // construct vector
        vector<string> vecStr(numRows);
        for (int i = 0; i < nCount; i++) {
            if (r == 0) {
                step = 1;
            }

            vecStr[r] += s[i];
            r = r + step;
            
            if (r == numRows-1) {
                step = -1;
            }
        }
        string ret;
        for (int j = 0; j < numRows; j++) {
            ret += vecStr[j];
        }
        return ret;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 0; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);
        
        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
