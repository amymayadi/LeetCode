/**
 * M228SummaryRanges2.cpp
 * Runtinme:
 * time: O(n)
 * space: O(n)
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>


using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty())
            return ranges;

        int start = nums[0], end = nums[0];
        for (int i = 1; i <= nums.size(); ++i) {
            if(i < nums.size() && nums[i] == end+1){
                end = nums[i];
            } else {
                // auto&&: I will accept any initializer regardless of
                // whether it is an lvalue or rvalue expression and I will preserve its constness.
                auto&& range = to_string(start);
                if (start != end){
                    range.append("->" + to_string(end));
                }
                // 在容器尾部添加一个元素，这个元素原地构造，不需要触发拷贝构造和转移构造。
                // 而且调用形式更加简洁，直接根据参数初始化临时对象的成员。
                ranges.emplace_back(range);
                if(i < nums.size()) {
                    start = end = nums[i];
                }
            }
        }
        return ranges;
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
