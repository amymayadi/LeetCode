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
        return majorityElement(nums, 0, nums.size()-1).first;
    }
private:
    // !!return pair<int, int>!!
    pair<int, int> majorityElement(const vector<int>& nums, int lt, int rt) {
        //cout<< "left:" << lt << " right:" << rt <<endl;
        if (lt == rt) return {nums[lt],1};
        const int m = lt + (rt - lt)/2;
        auto ml = majorityElement(nums, lt, m);
        auto mr = majorityElement(nums, m+1, rt);
        if (ml.first == mr.first) return {ml.first, ml.second+mr.second};
        if (ml.second > mr.second)
            // ml's count is bigger then ml is majority
            // ml.first count is ml.count + ml.first's count in the other part of the nums
            return {ml.first, ml.second + count(nums.begin()+m+1, nums.rt, ml.first)};
        else
            return {mr.first, mr.second + count(nums.begin()+lt, nums.begin()+m, mr.first)};
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
