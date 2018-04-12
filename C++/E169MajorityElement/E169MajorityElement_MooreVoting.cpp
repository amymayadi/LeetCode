//
// Created by MaYadi on 2018/4/11.
//
/**
 *  Moore Voting
 *  time:O(n)
 *  space:O(1)
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums.front();
        int count = 0;

        for (const int num : nums) {
            if (num == majority) count++;
            else if(count-- == 0) { // not majority then count-1, if count is already one then update majority
                count = 1;
                majority = num; // majority may be wrong num when nums has no majority.[1,2,2,3],3 is not majority 
            }
        }
        return majority;
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

