#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution{
//public:
//    void printHello(){
//        std::cout<<"hello world"<<std::endl;
//    }
//    time:O(n^2) space:O(n)
//    vector<int> twoSum(vector<int> &nums, int target) {
//        vector<int> res;
//        int n = nums.size();
//        for (int i = 0; i < n; i++)
//            for (int j = i + 1; j < n; j++) {
//                if (nums[j] == (target - nums[i])) {
//                    res.push_back(i);
//                    res.push_back(j);
//                    return res;
//                    //return {i, j};
//                }
//            }
//    }
//};

//  time:O(n)
//  space:O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map1;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            map1[nums[i]] = i;
            int numToFind = target - nums[i];
            if(map1.find(numToFind) != map1.end() && numToFind != nums[i]){
                res.push_back(i);
                int j = map1[numToFind];
                res.push_back(j);
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    //s.printHello();
    vector<int> nums ={2,5,7,9};
    vector<int> c = s.twoSum(nums, 14);
    for (int d:c)  // d为遍历c中所取的值
        cout<<d<<endl;
}
