/**
 * 难度：简单
 * 
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


    示例 1:

    输入: nums = [-1,0,3,5,9,12], target = 9
    输出: 4
    解释: 9 出现在 nums 中并且下标为 4
    示例 2:

    输入: nums = [-1,0,3,5,9,12], target = 2
    输出: -1
    解释: 2 不存在 nums 中因此返回 -1
     

    提示：

    你可以假设 nums 中的所有元素是不重复的。
    n 将在 [1, 10000]之间。
    nums 的每个元素都将在 [-9999, 9999]之间。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/binary-search
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度O(logn) 空间复杂度O(1)
// 法一 左闭右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1; //这里我忘记减一，需要特别注意
        int left = 0, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// 法二 左闭右开
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size(); //这里就不需要减一
        int left = 0, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    Solution solution;
    Solution1 solution1;
    int target = 12;
    cout << solution.search(nums, target) << endl;

    cout << "search2 result is: " << endl;
    cout << solution1.search(nums, target) << endl;
    return 0;
}