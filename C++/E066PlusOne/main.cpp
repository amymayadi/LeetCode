#define __USE_MINGW_ANSI_STDIO 0 //multiply definition of 'vsnprintf'

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for(int i = ((int)digits.size()-1); i >= 0; i--) {
            if ((digits[i] + flag) != 10) {
                digits[i] += flag;
                flag = 0;
            } else {
                digits[i] = 0;
                flag = 1;
            }
        }
        if (1 == flag)
            digits.insert(digits.begin(),1);
        return digits;
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
        vector<int> digits = stringToIntegerVector(line);

        int i = 0;
        for (int d :digits) {
            cout<< "digits " << ++i << ":" << d <<endl;
        }

        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
