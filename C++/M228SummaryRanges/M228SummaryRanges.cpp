/**
 * M228SummaryRanges
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
        vector<string> ans(0,"");
        if(nums.size() == 0) return ans;
        int L,R;
        //to_array
        L = R = nums[0];//初始化左右指针
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == R+1)//尝试将右指针进行拓展
            {
                R = nums[i];
            }
            else
            {
                ans.push_back(generate_str(L,R));//无法拓展则合并区间，并移动指针
                L = R = nums[i];
            }
        }
        ans.push_back(generate_str(L,R));
        return ans;
    }
    string generate_str(const int &L, const int &R)
    {
        if(L == R)
            return to_string(L);
        else return to_string(L) + "->" + to_string(R);
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
