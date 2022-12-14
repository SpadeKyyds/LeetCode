/**
 * 难度：简单
 * 
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

     

    说明:

    为什么返回数值是整数，但输出的答案是数组呢?

    请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

    你可以想象内部操作如下:

    // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
    int len = removeElement(nums, val);

    // 在函数里修改输入数组对于调用者是可见的。
    // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
    for (int i = 0; i < len; i++) {
        print(nums[i]);
    }
     

    示例 1：

    输入：nums = [3,2,2,3], val = 3
    输出：2, nums = [2,2]
    解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
    示例 2：

    输入：nums = [0,1,2,2,3,0,4,2], val = 2
    输出：5, nums = [0,1,4,0,3]
    解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
     

    提示：

    0 <= nums.length <= 100
    0 <= nums[i] <= 50
    0 <= val <= 100

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/remove-element
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

// 自创解法：反向遍历数组，遇到目标值将之和数组中最后一个元素交换，同时数组长度减一
// 时间复杂度O(n) 空间复杂度O(1)
// 在目标元素值占比较少的情况下优于快慢指针法，元素赋值操作次数较少，但元素乱序了，这是不足
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size() - 1;
        for (int i = len; i >= 0; --i) {
            if (nums[i] == val) {
                int temp = nums[i];
                nums[i] = nums[len];
                nums[len] = temp;
                --len;
            }
        }
        return ++len;
    }
};

// 快慢指针法
// 快指针：寻找新数组的元素，新数组即为不含目标元素的数组
// 慢指针：指向新数组
// 时间复杂度O(n) 空间复杂度O(1) 在数组、链表、字符串中应用频繁
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
            if (nums[fastIndex] != val) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex; //这里不需要加一，因为最后一次赋值操作后自增了
    }
};

// 快慢指针优化 经典版本 时间复杂度O(n) 空间复杂度O(1)
// 基本思想：左指针从左往右扫描，右指针从右往左，当左指针扫描到目标值时，右指针指向的值赋给左指针指向的值，
// 右指针左移，当左指针指向的值不为目标值时，左指针右移，当左指针大于右指针时，结束循环，返回左指针索引即为新数组长度。
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int lIndex = 0, rIndex = nums.size() - 1;
        while (lIndex <= rIndex) {
            if (nums[lIndex] == val) {
                nums[lIndex] = nums[rIndex--];
            } else {
                ++lIndex;
            }
        }
        return lIndex;
    }
};

void print(vector<int>& nums, int len) {
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    Solution s;
    int len = s.removeElement(nums, 3);
    print(nums, len);

    return 0;
}