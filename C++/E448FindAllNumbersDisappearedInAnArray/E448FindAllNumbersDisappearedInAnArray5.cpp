/**
 * Runtime:169ms -- SLOW
 * time:O(n)
 * space:O(1)
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>

using namespace std;
// 默认参数声明，应该在调用函数之前。
string integerVectorToString(vector<int> list, int length);
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n==0 || n==1) {
            return res;
        }
        for (int i = 0; i <= n; ++i) {
            res.push_back(0);
        }
        for (int l = 0; l < n; ++l) {
            res[nums[l]] = -1;
        }
        int j = 0;
        for (int k = 1; k <= n; ++k) {
            if(res[k] == 0)
                res[j++] = k;
        }
        auto it = res.begin()+j;
        res.erase(it, res.end());
        return  res;
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
// 不允许多处声明默认参数，只允许声明一次
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

        vector<int> ret = Solution().findDisappearedNumbers(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
