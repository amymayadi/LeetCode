/**
 * E283MoveZeroes.cpp
 * Runtinme: 13ms -- FAST
 * time: O(n)
 * space: O(1)
 * Created by MA YADI on 2018/4/16.
 * Copyright © 2018年 Ya-Di Ma. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <include/c++/algorithm>
#include <sstream>

using namespace std;

static const auto __________ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zp = 0;
        bool first = true;
        for (int i = 0; i < n ; i++) {
            if(first) {
                if (nums[i] == 0) {
                    first = false;
                    zp = i;
                }
            }else{
                if(nums[i] != 0)
                {
                    nums[zp++] = nums[i];
                }
            }
        }
        if (!first){
            for (int j = zp; j < n; ++j) {
                nums[j] = 0;
            }
        }
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
        vector<int> nums = stringToIntegerVector(line);

        Solution().moveZeroes(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
