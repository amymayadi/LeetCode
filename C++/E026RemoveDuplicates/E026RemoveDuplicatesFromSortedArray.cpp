//  Runtime: 30 ms

//  time:O(n)
//  space:O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int j = 1; //待存位置
        int key=nums[0];
        for(int i=1; i<n; i++){
            if(key != nums[i]){ //未判断数组起点
                key = nums[i];
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
