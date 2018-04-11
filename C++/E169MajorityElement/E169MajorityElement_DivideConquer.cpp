//
// Created by MaYadi on 2018/4/11.
//
/**
 *  Divide and Conquer
 *  time:O(nlogn)
 *  space:O(logn)
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size()-1);
    }
private:
    int majorityElement(const vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        const int middle = left + (right - left)/2;
        const int ml = majorityElement(nums, left, middle);
        const int mr = majorityElement(nums, middle+1, right);
        if (ml == mr) return ml;
        // count(): stl_vector method to count ml in vector nums
        int cl = count(nums.begin()+1eft,nums.begin()+right,ml);
        int cr = count(nums.begin()+1eft,nums.begin()+right,mr);
        return (cl>cr?ml:mr);
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
