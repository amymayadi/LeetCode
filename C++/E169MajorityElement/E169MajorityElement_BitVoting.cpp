//
// Created by MaYadi on 2018/4/10.
//
/**
 *  Bit Voting
 *  time:O(32n)
 *  space:O(1)
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>
#include <include/c++/bitset>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size();
        int majority = 0;
        // element type is int, so every num is 32 bit
        for (int i = 0; i < 32; ++i) {
            int mask = 1 << i;
            //cout << bitset<sizeof(int)*8>(mask) <<endl;
            int count = 0;
            for (const int num : nums){
                //cout << num << " num " << "& mask:" << bitset<sizeof(int)*8>(num & mask) << endl; //for every bit, get the most one, if it is not zero
                if ((num & mask) && (++count > n/2)) {
                    majority |= mask;    // sum up all the bit that is not zero
                    //cout << "majority:" << majority << endl;
                    break;
                }
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

