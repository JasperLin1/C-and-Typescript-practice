#include <iostream>
#include <string>
#include <stack> // 核心：使用 C++ 官方 STL 的 stack！

// ========================================================
// 🎯 LeetCode 第 20 題：Valid Parentheses (有效括號)
// ========================================================
// 這題我們之前用「自己手寫的 Stack 類別」挑戰過。
// 現在，我們要用 C++ 官方 STL 提供的 `std::stack` 來寫！
// 你會發現：官方的 stack 使用起來跟你自己寫的幾乎一模一樣，而且完全不需要去寫動態陣列跟 delete！
//
// 💡 C++ STL stack 的常用指令對照表：
// - 宣告：`std::stack<char> s;` (自動適應容量，不需要像我們之前那樣傳入長度！)
// - 壓入：`s.push(ch);`
// - 彈出：`s.pop();` (注意：STL 的 pop 是 void，不會回傳值，只會把最上面的元素刪掉)
// - 看最上方：`s.top();` (在我們手寫的 stack 裡，我們命名為 peek()，官方命名為 top())
// - 檢查空：`s.empty();` (官方命名為 empty()，我們之前命名為 isEmpty())

// TODO: 請實作 isValidParentheses 函式 (使用官方 std::stack)
bool isValidParentheses(std::string str) {
    // 1. 宣告一個官方 stack，型態為 char。命名為 `s`。
    // [在此寫下宣告代碼]
    std::stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // 2. 如果是左括號 '(', '[', '{' ➡️ push 進 stack
        // [在此寫下代碼]
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }


        // 3. 如果是右括號 ➡️
        //    - 檢查 stack 是否為空 (s.empty())，或者是配對失敗。
        //    - 注意：查看最上方元素要用 `s.top()`，配對成功要用 `s.pop()` 彈出。
        // [在此寫下代碼]
        else if (ch == ')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
        else if (ch == ']'){
            if(s.empty() || s.top() != '['){
                return false;
            }
            s.pop();
        }
        else if (ch == '}'){
            if(s.empty() || s.top() != '{'){
                return false;
            }
            s.pop();
        }
        // 提示：
        // else if (ch == ')') {
        //     if (s.empty() || s.top() != '(') return false;
        //     s.pop();
        // }
        // ...其他右括號比照辦理
        

    }

    // 4. 回傳 stack 最後是否為空
    // 提示：回傳 `s.empty()`
    return s.empty();
}

int main() {
    std::cout << "=== 測試 LeetCode 20: Valid Parentheses (STL 版) ===" << std::endl;

    std::string test1 = "()[]{}";
    std::string test2 = "([)]";
    std::string test3 = "{[()]}";

    std::cout << test1 << " : " << (isValidParentheses(test1) ? "有效" : "無效") << " (預期: 有效)" << std::endl;
    std::cout << test2 << " : " << (isValidParentheses(test2) ? "有效" : "無效") << " (預期: 無效)" << std::endl;
    std::cout << test3 << " : " << (isValidParentheses(test3) ? "有效" : "無效") << " (預期: 有效)" << std::endl;

    return 0;
}
