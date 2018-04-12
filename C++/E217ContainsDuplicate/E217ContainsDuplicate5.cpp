/**
 * time:O(n)
 * space:O(logn)
 * Runtime:19ms
 */
#include <iostream>
#include <vector>
#include <include/c++/unordered_map>
#include <include/c++/algorithm>
#include <include/c++/sstream>

using namespace std;

int x=[](){    // NO these code Runtime:33ms
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        int i = 0;
        int n = nums.size();
        while(i<n){
            if(++hash[nums[i++]]>1)
                return true;
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().containsDuplicate(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
