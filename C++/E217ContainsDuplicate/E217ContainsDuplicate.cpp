#include <iostream>
#include <vector>
#include <include/c++/unordered_map>
#include <include/c++/algorithm>
#include <include/c++/sstream>
#include <include/c++/unordered_set>

using namespace std;

int x=[](){    // NO these code Runtime:33ms
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }

    bool containsDuplicate2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // unique() @brief: Remove consecutive duplicate values from a sequence.
        //          @return: An iterator designating the end of the resulting sequence.
        return unique(nums.begin(),nums.end()) != nums.end();
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
        //bool ret = Solution().containsDuplicate2(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
