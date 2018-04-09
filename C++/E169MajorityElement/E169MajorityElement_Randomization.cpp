//  Randomization
//  time:O(n)
//  space:O(1)
#include <iostream>
#include <vector>
#include <sstream>
#include <include/c++/algorithm>
#include <include/c++/ctime>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        srand(time(nullptr));
        const int n = nums.size();
        while(true) {
            const int index = rand() % n;
            // high probability to get the majority num
            // if not, re-generate the majority and search to find its count
            const int majority = nums[index];
            int count = 0;
            for (const int num : nums) {
                if(num == majority && ++count > n/2)
                    return num;
            }
        }
        return -1;
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
