/**
 * Runtime:109ms -- FAST
 * time:O(n)
 * space:O(1)
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>
using namespace std;
int x=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int tmp = abs(nums[i])-1;
            if (tmp > 0){
                if(nums[tmp] > 0){
                    nums[tmp] = -nums[tmp];
                }
            } else{
                tmp = -tmp;
                if(nums[tmp] > 0){
                    nums[tmp] = -nums[tmp];
                }
            }
        }
        vector<int> ans;
        for (int j = 0; j < len; ++j) {
            int tmp = nums[j];
            if (tmp > 0){
                ans.push_back(j+1);
            }
        }
        return ans;
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
