/**
 * 简单
 * 
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

    在 S 上反复执行重复项删除操作，直到无法继续删除。

    在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

     

    示例：

    输入："abbaca"
    输出："ca"
    解释：
    例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

    来源：力扣（LeetCode）
    链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
using namespace std;

// 栈的特殊结构非常适合做对称匹配或者相邻匹配的问题
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> characterStack;
        for (auto ch : s) {
            if (characterStack.empty() || ch != characterStack.top()) characterStack.push(ch);
            else characterStack.pop();
        }
        int size = characterStack.size();
        s.resize(size);
        for (int i = size - 1; i >= 0; --i) {
            s[i] = characterStack.top();
            characterStack.pop();
        }
        return s;
    }
};