#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int i, j, imin = 0, imax = m, half = (m + n + 1) / 2;
        while (imin <= imax) {
            int c = imin & imax;
            int d = (imin ^ imax) >> 1;
            int t = floor((imin+imax)/2);
            i = (imin & imax) + ((imin ^ imax) >> 1);
            int e = (t==i);
            cout<<e<<endl;
            assert(t==i);
            j = half - i;
            if (i > 0 && j < n && nums1[i - 1] > nums2[j]) imax = i - 1;
            else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) imin = i + 1;
            else break;
        }
        int num1;
        if (!i) num1 = nums2[j - 1];
        else if (!j) num1 = nums1[i - 1];
        else num1 = max(nums1[i - 1], nums2[j - 1]);
        if ((m + n) & 1) return num1;
        int num2;
        if (i == m) num2 = nums2[j];
        else if (j == n) num2 = nums1[i];
        else num2 = min(nums1[i], nums2[j]);
        return (num1 + num2) / 2.0;
    }
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Solution s;
//    vector<int> v1={1,3};
//    vector<int> v2={2,4};
    vector<int> v1={10, 12, 30, 32, 66};
    vector<int> v2={12, 21, 25, 36, 40, 49, 50, 91};
    double d = s.findMedianSortedArrays(v1,v2);
    cout<<d<<endl;

    return 0;
}