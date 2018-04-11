//
// Created by MaYadi on 2018/4/11.
//
/**
 *  Full Sorting
 *  time:O(n) on average
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
        // The other elements are left without any specific order,
        // except that none of the elements preceding nth are greater than it,
        // and none of the elements following it are less.
        nth_element(nums.begin(), nums.begin() + 1, nums.end());
        return nums[0];
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
