#define __USE_MINGW_ANSI_STDIO 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution {
public:
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n -1, d = m + n - 1;
        while(i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j])
                nums1[d--] = nums2[j--];
            else
                nums1[d--] = nums1[i--];
        }
        // nums1 i < 0
        while (j >= 0) {
            nums1[d--] = nums2[j--];
        }
        return;
//        int i = m-1, j = n-1;
//        int d = m+n-1;
//        for(; i>=0&&j>=0; d--) {
//            if (nums1[i] < nums2[j])
//                nums1[d] = nums2[j--];
//            else
//                nums1[d] = nums1[i--];
//        }
//        for(;j>=0;j--) {
//            nums1[d--] = nums2[j];
//        }
//        return;
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

int stringToInteger(string input) {
    return stoi(input);
}

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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);

        Solution().merge(nums1, m, nums2, n);

        string out = integerVectorToString(nums1);
        cout << out << endl;
    }
    return 0;
}
